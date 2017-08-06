#include "character_queue.h"

int* full_matrix_leds;

int main() {
  struct character_queue* main_list = initialize_list();
  character_function* LETTER_A = get_array_of_characters();

  insert_character(main_list, LETTER_A[0], 5);
  insert_character(main_list, LETTER_A[1], 5);
  insert_character(main_list, LETTER_A[2], 5);
  scroll_text(main_list);
  
  destroy_list(main_list);
  free(LETTER_A);
}

// ==========================================================================================


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


void combine_list(int*, int*);
void get_valid_lights_queue(struct character_queue*, int*);

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


void scroll_text(struct character_queue* list) {
  int* current_lights = malloc((1 + LIGHTS) * sizeof(int));
  int* next_generation_lights = malloc((1 + LIGHTS) * sizeof(int));

  current_lights[0] = 0;
  next_generation_lights[0] = 0;

  while(1) {
    get_valid_lights_queue(list, current_lights);
    turn_on_list(list->m_i2c_item, current_lights);
    increment_list(list);
    get_valid_lights_queue(list, next_generation_lights);
    usleep(50000);
    turn_off_list(list->m_i2c_item, current_lights);
  }

  free(current_lights);
  free(next_generation_lights);
}


void destroy_list(struct character_queue* list) {

  // have to dlete all elements in the list
  
  i2c_base_destroy(list->m_i2c_item);
  Character_leds_destroy();
  free(list);
}


