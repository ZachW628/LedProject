/*
* Author: Zachary WIlliams
* Descprtion: Initial testing file for GPIO operations on MCP23017 I/O Expander
*/


#include "characters.h"

int* character_leds;

int main() {
  Character_leds_init();
  int* test_list = letter_A(12, 1);

  struct i2c_base* base_layer = malloc(sizeof(struct i2c_base));;
  i2c_base_init(base_layer);

  for (int i = 1; i < test_list[0] + 1; i++) {
    printf("Total number %d\n actual value: %d\n", test_list[0], test_list[i]); 
  }

  base_layer->map(*base_layer->file_descriptor_1, *base_layer->file_descriptor_1, test_list, HIGH); 


  i2c_base_destroy(base_layer);
  free(character_leds);
}


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
  for (int i = 1; i < 41; i++) {
    character_leds = malloc(41 * sizeof(int));
  }
}

int converter(int x) {
  int multiplier = x / 16;
  int pin = pinner(x % 16);

  return ((multiplier* 16) + pin);
}

/*
void initialize_setup() {
  wiringPiSetup();
 
  mcp23017Setup(BASE, 0x20);
  mcp23017Setup((BASE + 16), 0x21);
  mcp23017Setup((BASE + 32), 0x22);
  mcp23017Setup((BASE + 48), 0x23);
  mcp23017Setup((BASE + 64), 0x24);
  mcp23017Setup((BASE + 80), 0x25);
  mcp23017Setup((BASE + 96), 0x26);
  mcp23017Setup((BASE + 112), 0x27);

  printf("Setup Complete!!!\n"); 

  for (int i = 0; i < LIGHTS; i++)
    pinMode((BASE + i), OUTPUT);
}


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

void validate_light(int number_for_light, int state) {
  printf("Validate light\n");
  int column = (number_for_light - BASE) / 8;
  if (column >= 0 && column <= NUMBER_COLUMNS) {
    character_leds[character_leds[0] + 1] = number_for_light;
    character_leds[0] += 1; 
  }
}


int* letter_A(int column, int state) {
  character_leds[0] = 0;
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
  return character_leds;
}

/*
void letter_B(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);  
}


void letter_C(int column, int state) { 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}
*/
/*
void letter_D(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state); 
}


void letter_E(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);   
}


void letter_F(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);    
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);   
}


void letter_G(int column, int state) { 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);  
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);  
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
}


void letter_H(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);  
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_I(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state);
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);  
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_J(int column, int state) {
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 1)), state);
  validate_light((BASE + converter((column - 1) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_K(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_L(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state);
}


void letter_M(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 1)), state);
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
}


void letter_N(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 6)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
}


void letter_O(int column, int state) { 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state); 
}


void letter_P(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state);
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void letter_Q(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state);
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 2)), state);
  validate_light((BASE + converter((column - 3) * 8 + 3)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 6)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
}


void letter_R(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state);
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 1)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void letter_S(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state);  
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_T(int column, int state) {
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);  
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_U(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void letter_V(int column, int state) {
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 1)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void letter_W(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 6)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void letter_X(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state);
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 2)), state);
  validate_light((BASE + converter((column - 1) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 2)), state);
  validate_light((BASE + converter((column - 3) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}

void letter_Y(int column, int state) {
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void letter_Z(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state);
  validate_light((BASE + converter((column - 1) * 8 + 2)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void number_0(int column, int state) {  
  validate_light((BASE + converter(column * 8 + 2)), state); 
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state); 
}


void number_1(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state);
  validate_light((BASE + converter(column * 8 + 5)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);  
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 5)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state); 
}


void number_2(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 2)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 0)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);  
}


void number_3(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state);  
  validate_light((BASE + converter(column * 8 + 6)), state);
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state); 
}


void number_4(int column, int state) {
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state);
  validate_light((BASE + converter((column - 1) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 5)), state);
  validate_light((BASE + converter((column - 2) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 6)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 1)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 2)), state);
  validate_light((BASE + converter((column - 3) * 8 + 3)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 6)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state); 
}


void number_5(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 4)), state);
  validate_light((BASE + converter(column * 8 + 7)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 4)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 0)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void number_6(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state);
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 4)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state);
  validate_light((BASE + converter((column - 1) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 6)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 3)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
}


void number_7(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 7)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 2)), state);
  validate_light((BASE + converter((column - 1) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 3)), state);
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 5)), state);
  validate_light((BASE + converter((column - 3) * 8 + 7)), state); 
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
  validate_light((BASE + converter((column - 4) * 8 + 7)), state);
}


void number_8(int column, int state) {
  validate_light((BASE + converter(column * 8 + 1)), state); 
  validate_light((BASE + converter(column * 8 + 2)), state);
  validate_light((BASE + converter(column * 8 + 3)), state);
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 0)), state);
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 0)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 0)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 1)), state);
  validate_light((BASE + converter((column - 4) * 8 + 2)), state);
  validate_light((BASE + converter((column - 4) * 8 + 3)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}


void number_9(int column, int state) {
  validate_light((BASE + converter(column * 8 + 0)), state); 
  validate_light((BASE + converter(column * 8 + 5)), state); 
  validate_light((BASE + converter(column * 8 + 6)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 1)), state);
  validate_light((BASE + converter((column - 1) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 1) * 8 + 7)), state);
  validate_light((BASE + converter((column - 2) * 8 + 2)), state); 
  validate_light((BASE + converter((column - 2) * 8 + 4)), state);
  validate_light((BASE + converter((column - 2) * 8 + 7)), state);
  validate_light((BASE + converter((column - 3) * 8 + 3)), state);
  validate_light((BASE + converter((column - 3) * 8 + 4)), state); 
  validate_light((BASE + converter((column - 3) * 8 + 7)), state);
  validate_light((BASE + converter((column - 4) * 8 + 4)), state);
  validate_light((BASE + converter((column - 4) * 8 + 5)), state);
  validate_light((BASE + converter((column - 4) * 8 + 6)), state);
}
*/

character_function* get_array_of_characters() {
  character_function* characters;
  //characters = malloc(NUMBER_CHARACTERS * sizeof(character_function));
  characters = malloc(1 * sizeof(character_function));


  characters[0] = letter_A;
  //characters[1] = letter_B;
  //characters[2] = letter_C;
/*
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
*/
  return characters;
}
















