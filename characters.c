/*
* Author: Zachary WIlliams
* Descprtion: Initial testing file for GPIO operations on MCP23017 I/O Expander
*/


#include "characters.h"

int* character_leds;


int pinner(int x) {
  if (x == 0)
    return 15;
  else if (x == 1)
    return 14;
  else if (x == 2)
    return 13;
  else if (x == 3)
   return 12;
  else if (x == 4)
    return 11;
  else if (x == 5)
    return 10;
  else if (x == 6)
    return 9;
  else if (x == 7)
    return 8;
  else if (x == 8)
    return 7;
  else if (x == 9)
    return 6;
  else if (x == 10)
    return 5;
  else if (x == 11)
    return 4;
  else if (x == 12)
    return 3;
  else if (x == 13)
    return 2;
  else if (x == 14)
    return 1;
  else if (x == 15)
    return 0;
}


void Character_leds_init() {
  character_leds = malloc(41 * sizeof(int));
  character_leds[0] = 0;
}


void Character_leds_destroy() {
  free(character_leds);
}


int converter(int x) {
  int multiplier = x / 16;
  int pin = pinner(x % 16);

  return ((multiplier* 16) + pin);
}


/*
void all_off() {
  for (int i = 0; i < LIGHTS; i++)
    digitalWrite((BASE + converter(i)), LOW);
}


void all_on() {
  for (int i = 0; i < LIGHTS; i++)
    digitalWrite((BASE + converter(i)), HIGH);
}


void cycle_all() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < LIGHTS / 8; j++) {
      if (((i * 16) + j) <= LIGHTS) {
        digitalWrite((BASE + converter(i*16 + j)), HIGH);
        delay(DELAY);
        digitalWrite((BASE + converter(i * 16 + j)), LOW);
        delay(DELAY);
      }
    }
  }
}


void cycle_characters(character_function* characters) {
  for (int i = 0; i < NUMBER_CHARACTERS; i++) {
    characters[i](11, HIGH);
    delay(DELAY);
    characters[i](11, LOW);
    delay(DELAY);
  }
}
*/


void validate_light(int number_for_light) {
  int column = (number_for_light) / 8;
  if (column >= 0 && column <= NUMBER_COLUMNS) {
    character_leds[character_leds[0]+1] = number_for_light;
    character_leds[0] += 1; 
  }
}


int* Special_SPACE(int column) {
  character_leds[0] = 0;
  return character_leds;
}


int* Special_EXCLAMATION(int column) {
  character_leds[0] = 0;
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 2)); 
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 7));
  return character_leds;
}


int* Special_QOUTE(int);


int* Special_HASHTAG(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 1)); 
  validate_light(converter((column - 1) * 8 + 2)); 
  validate_light(converter((column - 1) * 8 + 3));
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 2)); 
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 5)); 
  validate_light(converter((column - 3) * 8 + 6)); 
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 5));
  return character_leds;
}


int* Special_QWERTY(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1));  
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 5));
  validate_light(converter((column - 1) * 8 + 1)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 6)); 
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));  
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 1));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* Special_MOD(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));  
  validate_light(converter(column * 8 + 1));
  validate_light(converter(column * 8 + 6));
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 2)); 
  validate_light(converter((column - 1) * 8 + 3));
  validate_light(converter((column - 1) * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 3) * 8 + 0));  
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 6)); 
  validate_light(converter((column - 3) * 8 + 7));
  return character_leds;
}


int* Special_AND(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 3) * 8 + 1));
  validate_light(converter((column - 3) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 2));
  return character_leds;
}


int* Special_Apostrophe(int column) {

}


int* Special_LEFT_PAREN(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 6)); 
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 7));
  return character_leds;
}


int* Special_RIGHT_PAREN(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 6)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 5));
  return character_leds;
}


int* Special_STAR(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 5));
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* Special_PLUS(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 3));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 1));
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 3));
  return character_leds;
}


int* Special_COMMA(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));  
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 2));
  return character_leds;
}


int* Special_MINUS(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 3));
  validate_light(converter((column - 1) * 8 + 3));  
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 3));
  return character_leds;
}


int* Special_PERIOD(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 0));
  validate_light(converter(column * 8 + 1));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 1));
  return character_leds;
}


int* Special_FOR_SLASH(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));  
  validate_light(converter(column * 8 + 1));
  validate_light(converter((column - 1) * 8 + 2)); 
  validate_light(converter((column - 1) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5));  
  validate_light(converter((column - 3) * 8 + 6)); 
  validate_light(converter((column - 3) * 8 + 7));
  return character_leds;
}


int* number_0(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 1)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5));
  return character_leds; 
}


int* number_1(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));
  validate_light(converter(column * 8 + 5));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));  
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 0));
  return character_leds; 
}


int* number_2(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1));
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;  
}


int* number_3(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1));  
  validate_light(converter(column * 8 + 6));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds; 
}


int* number_4(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 2));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 6)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 3));
  return character_leds; 
}


int* number_5(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 4));
  validate_light(converter(column * 8 + 7));
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* number_6(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 3)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  return character_leds;
}


int* number_7(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* number_8(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* number_9(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* Special_COLON(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 1) * 8 + 6));
  return character_leds;
}


int* Special_SEMI_COLON(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));  
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 1) * 8 + 6));
  return character_leds;
}


int* Special_LEFT_CARET(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 2) * 8 + 1));
  validate_light(converter((column - 2) * 8 + 6));
  return character_leds;
}


int* Special_EQUAL(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 5));  
  validate_light(converter((column - 1) * 8 + 3));
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 5));
  return character_leds;
}


int* Special_RIGHT_CARET(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 5));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  return character_leds;
}


int* Special_QUESTION(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* Special_AT(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 2));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 6));
  validate_light(converter((column - 5) * 8 + 1));
  validate_light(converter((column - 5) * 8 + 2));
  validate_light(converter((column - 5) * 8 + 3));
  validate_light(converter((column - 5) * 8 + 4));
  validate_light(converter((column - 5) * 8 + 5));
  return character_leds;
}


int* letter_A(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 3)); 
  validate_light(converter((column - 3) * 8 + 7));  
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 1));  
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));  
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_B(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 1)); 
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_C(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 7));  
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_D(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6));
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 7));  
  validate_light(converter((column - 4) * 8 + 1)); 
  validate_light(converter((column - 4) * 8 + 2));  
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 4));  
  validate_light(converter((column - 4) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_E(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;   
}


int* letter_F(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 7));    
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;   
}


int* letter_G(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7));  
  validate_light(converter((column - 3) * 8 + 0));  
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3));
  return character_leds;
}


int* letter_H(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 4));  
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 1));  
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));  
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_I(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));  
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_J(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 1) * 8 + 2)); 
  validate_light(converter((column - 1) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6)); 
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_K(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_L(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 0));
  return character_leds;
}


int* letter_M(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 1));
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5));
  return character_leds;
}


int* letter_N(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter((column - 1) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 6)); 
  validate_light(converter((column - 3) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 0)); 
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5));
  return character_leds;
}


int* letter_O(int column) {
  character_leds[0] = 0; 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3));
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 4)); 
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds; 
}


int* letter_P(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 4)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 4)); 
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_Q(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 3) * 8 + 2));
  validate_light(converter((column - 3) * 8 + 3));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 6)); 
  validate_light(converter((column - 4) * 8 + 0));
  return character_leds; 
}


int* letter_R(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1));
  validate_light(converter(column * 8 + 2));
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4)); 
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 3)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 1));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_S(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0));  
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6));
  validate_light(converter((column - 1) * 8 + 0)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 7));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 2)); 
  validate_light(converter((column - 4) * 8 + 3));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_T(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 7));
  validate_light(converter((column - 1) * 8 + 7));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2)); 
  validate_light(converter((column - 2) * 8 + 3));  
  validate_light(converter((column - 2) * 8 + 4)); 
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 2) * 8 + 7));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_U(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4));
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 1)); 
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_V(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4));
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 1));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 3) * 8 + 1)); 
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_W(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 2)); 
  validate_light(converter(column * 8 + 3)); 
  validate_light(converter(column * 8 + 4));
  validate_light(converter(column * 8 + 5));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 6));
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 1)); 
  validate_light(converter((column - 4) * 8 + 2));
  validate_light(converter((column - 4) * 8 + 3)); 
  validate_light(converter((column - 4) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 6));
  return character_leds;
}


int* letter_X(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1));
  validate_light(converter(column * 8 + 6)); 
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 5)); 
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 3) * 8 + 2));
  validate_light(converter((column - 3) * 8 + 5)); 
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 1));
  validate_light(converter((column - 4) * 8 + 6)); 
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}

int* letter_Y(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 5)); 
  validate_light(converter(column * 8 + 6));
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 0)); 
  validate_light(converter((column - 2) * 8 + 1)); 
  validate_light(converter((column - 2) * 8 + 2));
  validate_light(converter((column - 2) * 8 + 3)); 
  validate_light(converter((column - 3) * 8 + 4));
  validate_light(converter((column - 4) * 8 + 5));
  validate_light(converter((column - 4) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* letter_Z(int column) {
  character_leds[0] = 0;
  validate_light(converter(column * 8 + 0)); 
  validate_light(converter(column * 8 + 1)); 
  validate_light(converter(column * 8 + 7)); 
  validate_light(converter((column - 1) * 8 + 0));
  validate_light(converter((column - 1) * 8 + 2));
  validate_light(converter((column - 1) * 8 + 7)); 
  validate_light(converter((column - 2) * 8 + 0));
  validate_light(converter((column - 2) * 8 + 3));
  validate_light(converter((column - 2) * 8 + 4));
  validate_light(converter((column - 2) * 8 + 7)); 
  validate_light(converter((column - 3) * 8 + 0));
  validate_light(converter((column - 3) * 8 + 5));
  validate_light(converter((column - 3) * 8 + 7)); 
  validate_light(converter((column - 4) * 8 + 0));
  validate_light(converter((column - 4) * 8 + 6));
  validate_light(converter((column - 4) * 8 + 7));
  return character_leds;
}


int* Special_LEFT_BRACKET(int column) {}
int* Special_BACK_SLASH(int column) {}
int* Special_RIGHT_BRACKET(int column) {}
int* Special_UP_CARET(int column) {}
int* Special_UNDERSCORE(int column) {}
int* Special_BACK_TIC(int column) {}

// After this we need to do more math to make the array linear
int* Special_LEFT_CURLY_BRACKET(int column) {}
int* Special_VERTICAL_BAR(int column) {}
int* Special_RIGHT_CURLY_BRACKET(int column) {}
int* Special_TILDA(int column) {}


character_function* get_array_of_characters() {
  character_function* characters;
  characters = malloc(NUMBER_CHARACTERS * sizeof(character_function));
  //characters = malloc(1 * sizeof(character_function));


  characters[26] = number_0;
  characters[27] = number_1;
  characters[28] = number_2;
  characters[29] = number_3;
  characters[30] = number_4;
  characters[31] = number_5;
  characters[32] = number_6;
  characters[33] = number_7;
  characters[34] = number_8;
  characters[35] = number_9;

  characters[0] = letter_A;
  characters[1] = letter_B;
  characters[2] = letter_C;
  characters[3] = letter_D;
  characters[4] = letter_E;
  characters[5] = letter_F;
  characters[6] = letter_G;
  characters[7] = letter_H;
  characters[8] = letter_I;
  characters[9] = letter_J;
  characters[10] = letter_K;
  characters[11] = letter_L;
  characters[12] = letter_M;
  characters[13] = letter_N;
  characters[14] = letter_O;
  characters[15] = letter_P;
  characters[16] = letter_Q;
  characters[17] = letter_R;
  characters[18] = letter_S;
  characters[19] = letter_T;
  characters[20] = letter_U;
  characters[21] = letter_V;
  characters[22] = letter_W;
  characters[23] = letter_X;
  characters[24] = letter_Y;
  characters[25] = letter_Z;
  return characters;
}
















