#include <stdio.h>
#include <stdlib.h>
#include "characters.h"


struct character_item {
  character_function m_character_function;
  int m_length;
  int m_position;
  struct character_item* m_next;
  struct character_item* m_prev;
};


struct character_queue {
  struct character_item* m_head;
  struct character_item* m_tail;
  int m_current_length;
  int m_size;
};


void turn_on_list(struct character_queue*);
void turn_off_list(struct character_queue*);
void insert_character(struct character_queue*, character_function, int);
void increment_list(struct character_queue*);
void scroll_text(struct character_queue*);
//void delete_current_list(character_queue*);


void initialize_character_queue(struct character_queue*);
void initialize_character_queue(struct character_queue* item) {
  item->m_head = NULL;
  item->m_tail = NULL;
  item->m_current_length = -5;
  item->m_size = 0;
}


void initialize_character_item(struct character_item*);
void initialize_character_item(struct character_item* item) {
  item->m_character_function = NULL;
  item->m_length = 0;
  item->m_position = 0;
  item->m_next = NULL;
  item->m_prev = NULL;
}

struct character_queue* initialize_list();
struct character_queue* initialize_list() {
  initialize_setup();
  all_off();
  struct character_queue* new_list = malloc(sizeof(struct character_queue));
  initialize_character_queue(new_list);
  return new_list;
}




