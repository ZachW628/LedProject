#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "characters.h"
#include "i2c_base.h"

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
  struct i2c_base* m_i2c_item;
};

int kbhit();
void nonblock(int state);

struct character_queue* initialize_list();
void initialize_character_queue(struct character_queue*);
void initialize_character_item(struct character_item*);

void turn_on_list(struct i2c_base*, int*);
void turn_off_list(struct i2c_base*, int*);

void find_lights_to_turn_off(int*, int*);
void insert_character(struct character_queue*, character_function, int);
void increment_list(struct character_queue*);
void scroll_text(struct character_queue*);
void destroy_list(struct character_queue*);



