#include "letters_test_env.h"

int main() {
  Character_leds_init();
  struct i2c_base* i2c_item = i2c_base_init();


  //int* new_list = Special_(11);
  //int* new_list = Special_(11);
  //int* new_list = Special_TILDA(11);
  //int* new_list = Special_RIGHT_CURLY_BRACE(11);
  //int* new_list = Special_VERTICAL_BAR(11);
  //int* new_list = Special_LEFT_CURLY_BRACE(11);
  //int* new_list = Special_BACK_TIC(11);
  //int* new_list = Special_UNDERSCORE(11);
  //int* new_list = Special_UP_CARET(11);
  //int* new_list = Special_RIGHT_BRACKET(11);
  //int* new_list = Special_BACK_SLASH(11);
  //int* new_list = Special_LEFT_BRACKET(11);
  //int* new_list = Special_APOSTROPHE(11);
  //int* new_list = SPecial_QOUTE(11);


  //int* new_list = Special_AT(11);     ---------- This needs to be a better design
  //int* new_list = Special_QUESTION(11);
  //int* new_list = Special_RIGHT_CARET(11);
  //int* new_list = Special_EQUAL(11);
  //int* new_list = Special_LEFT_CARET(11);
  //int* new_list = Special_SEMI_COLON(11);
  //int* new_list = Special_COLON(11);
  //int* new_list = Special_FOR_SLASH(11);
  //int* new_list = Special_PERIOD(11);
  //int* new_list = Special_MINUS(11);
  //int* new_list = Special_COMMA(11);
  //int* new_list = Special_PLUS(11);
  //int* new_list = Special_STAR(11);
  //int* new_list = Special_RIGHT_PAREN(11);
  //int* new_list = Special_LEFT_PAREN(11);
  //int* new_list = Special_AND(11);
  //int* new_list = Special_MOD(11);
  //int* new_list = Special_QWERTY(11);
  //int* new_list = Special_EXCLAMATION(11);
  //int* new_list = Special_HASHTAG(11);
 
  turn_on_list(i2c_item, new_list);
  sleep(20);
  turn_off_list(i2c_item, new_list); 

  i2c_base_destroy(i2c_item);
  Character_leds_destroy();
}




void turn_on_list(struct i2c_base* i2c_item, int* list) {
  i2c_item->map(*i2c_item->file_descriptor_1, *i2c_item->file_descriptor_1, list, HIGH);
}


void turn_off_list(struct i2c_base* i2c_item, int* list) {
  i2c_item->map(*i2c_item->file_descriptor_1, *i2c_item->file_descriptor_1, list, LOW);
}
