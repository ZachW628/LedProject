#include "character_queue.h"

int main() {
  //initialize_setup();
  //all_off();
  struct character_queue* main_list = initialize_list();
  character_function* LETTER_A = get_array_of_characters();
  insert_character(main_list, LETTER_A[0], 5);
  insert_character(main_list, LETTER_A[1], 5);
  insert_character(main_list, LETTER_A[2], 5);
  scroll_text(main_list); 
  //letter_A(14, HIGH);
  /*
  character_function* characters = get_array_of_characters();
  while(1) {
    cycle_characters(characters);
  }
  free(characters);
  */
}

// ==========================================================================================

void turn_on_list(struct character_queue* list) {
  struct character_item* temp = list->m_head;
  while (temp != NULL) {
    temp->m_character_function(temp->m_position, HIGH);
    temp = temp->m_next;
  }
}


void turn_off_list(struct character_queue* list) {
  struct character_item* temp = list->m_head;
  while (temp != NULL) {
    temp->m_character_function(temp->m_position, LOW);
    temp = temp->m_next;
  }
}


void insert_character(struct character_queue* list, character_function item, int length) {
  struct character_item* new_character_item = malloc(sizeof(struct character_item));
  initialize_character_item(new_character_item);
  new_character_item->m_character_function = item;
  new_character_item->m_length = length;
  new_character_item->m_position = list->m_current_length;
  list->m_current_length -= (length + 1);

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
  while(1) {
    turn_on_list(list);
    //increment_lisy(list);
    delay(DELAY);
    turn_off_list(list);
    increment_list(list);
  }
}

/*
void delete_current_list(character_queue* list) {

}
*/




