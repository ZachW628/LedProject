#include "character_queue.h"

enum icanon_state {
    NB_DISABLE,
    NB_ENABLE
};

int SLEEP =70000;

int main() {
  struct character_queue* main_list = initialize_list();
  character_function* LETTER_A = get_array_of_characters();

  insert_character(main_list, LETTER_A[25], 5);
  insert_character(main_list, LETTER_A[0], 5);
  insert_character(main_list, LETTER_A[2], 5);
  insert_character(main_list, LETTER_A[7], 5);
  scroll_text(main_list);
  
  destroy_list(main_list);
  free(LETTER_A);
}

// ==========================================================================================




void nonblock(int state) {
  struct termios cur_state;
  tcgetattr(STDIN_FILENO, &cur_state);
  if (state == NB_ENABLE) {
    cur_state.c_lflag &= ~ ICANON;
    cur_state.c_cc[VMIN] = 1;
  } else if (state == NB_DISABLE) {
    cur_state.c_lflag |= ICANON;
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &cur_state);
}


int kbhit() {
  struct timeval tv;
  fd_set fd;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fd);
  FD_SET(STDIN_FILENO, &fd);
  select(STDIN_FILENO+1, &fd, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fd);
}


struct character_queue* initialize_list() {
  Character_leds_init();
  struct character_queue* new_list = malloc(sizeof(struct character_queue));
  initialize_character_queue(new_list);
  //all_off();
  return new_list;
}


void initialize_character_queue(struct character_queue* item) {
  item->m_head = NULL;
  item->m_tail = NULL;
  item->m_current_length = -5;
  item->m_size = 0;
  item->m_i2c_item = i2c_base_init();
}


void initialize_character_item(struct character_item* item) {
  item->m_character_function = NULL;
  item->m_length = 0;
  item->m_position = 0;
  item->m_next = NULL;
  item->m_prev = NULL;
}


void turn_on_list(struct i2c_base* i2c_item, int* list) {
  i2c_item->map(*i2c_item->file_descriptor_1, *i2c_item->file_descriptor_1, list, HIGH);
}


void turn_off_list(struct i2c_base* i2c_item, int* list) {
  i2c_item->map(*i2c_item->file_descriptor_1, *i2c_item->file_descriptor_1, list, LOW);
}


void insert_character(struct character_queue* list, character_function item, int length) {
  /*
  :param list: This si the master list.
  :param item: the actual function that will be used.
  :param length: use 5 for default.
  */
  struct character_item* new_character_item = malloc(sizeof(struct character_item));
  initialize_character_item(new_character_item);
  new_character_item->m_character_function = item;
  new_character_item->m_length = length;
  new_character_item->m_position = list->m_current_length;
  list->m_current_length -= (length + 1);

  // Insert into list
  if (list->m_size == 0) {
    list->m_head = new_character_item;
    list->m_tail = new_character_item; 
  } else if (list->m_size == 1) {
    list->m_tail = new_character_item;
    list->m_head->m_next = new_character_item;
    new_character_item->m_prev = list->m_head;
  } else {
    struct character_item* temp = list->m_tail;
    list->m_tail = new_character_item;
    temp->m_next = new_character_item;
    new_character_item->m_prev = temp;
  }

  list->m_size += 1;
}


void combine_list(int* matrix_leds, int* character_list) {
  for (int i = 0; i < character_list[0]; i++) {
    matrix_leds[matrix_leds[0] + 1] = character_list[i + 1];
    matrix_leds[0] += 1;
  }
}


void get_valid_lights_queue(struct character_queue* list, int* led_list) {
  struct character_item* temp = list->m_head;
  led_list[0] = 0;
  int* temp_list;
  while (temp != NULL) {
    temp_list = temp->m_character_function(temp->m_position);
    combine_list(led_list, temp_list);
    temp = temp->m_next;
  }
}


void increment_list(struct character_queue* list) {
  struct character_item* temp = list->m_head;
  while (temp != NULL) {
    if (temp->m_position >= (10 + NUMBER_COLUMNS)) 
      temp->m_position = list->m_current_length - 10; 
    else
      temp->m_position += 1;
    temp = temp->m_next;
  }
}


void find_lights_to_turn_off(int* turn_off_list, int* next_on_light) {
  for (int i = 0; i < next_on_light[0]; i++) {
    remove_from_list(next_on_light[i + 1], turn_off_list);
  }
}

void remove_from_list(int number, int* list) {
  for (int i = 0; i < list[0]; i++) {
    if (number == list[i + 1]) {
      list[i + 1] = list[list[0]];
      list[0] -= 1;
      return;
    }
  }
}


void scroll_text(struct character_queue* list) {
  int* current_lights = malloc((1 + LIGHTS) * sizeof(int));
  int* next_generation_lights = malloc((1 + LIGHTS) * sizeof(int));

  current_lights[0] = 0;
  next_generation_lights[0] = 0;
  struct timeval start_time, end_time;

  nonblock(NB_ENABLE);
  while(!kbhit()) {
    gettimeofday(&start_time, NULL);
    get_valid_lights_queue(list, current_lights);
    turn_on_list(list->m_i2c_item, current_lights);
    increment_list(list);
    get_valid_lights_queue(list, next_generation_lights);
    find_lights_to_turn_off(current_lights, next_generation_lights);
    gettimeofday(&end_time, NULL);
    //usleep(SLEEP - (end_time.tv_usec - start_time.tv_usec));
    usleep(SLEEP);
    turn_off_list(list->m_i2c_item, current_lights);
  }
  nonblock(NB_DISABLE);

  free(current_lights);
  free(next_generation_lights);
}


void destroy_list(struct character_queue* list) {

  struct character_item* temp, *temp2;
  temp = list->m_head;
  while(temp != NULL) {
    temp2 = temp;
    temp = temp->m_next;
    free(temp2);
  }
  
  i2c_base_destroy(list->m_i2c_item);
  Character_leds_destroy();
  free(list);
}


