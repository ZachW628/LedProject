//#include <stdio.h>
//#include <stdlib.h>
#include "i2c_base.h"


#define BASE 64
#define DELAY 75
#define LIGHTS 112
#define NUMBER_CHARACTERS 36
#define NUMBER_COLUMNS 13 


typedef int* (*character_function)(int, int);


int converter(int);
int pinner(int);

void initialize_setup();
//void all_off();
//void all_on();

//void cycle_all();
//void cycle_characters(character_function*);

void Character_leds_init();

void validate_light(int, int);



int* letter_A(int, int);
//void letter_B(int, int);
//void letter_C(int, int);

/*
void letter_D(int, int);
void letter_E(int, int);
void letter_F(int, int);
void letter_G(int, int);
void letter_H(int, int);
void letter_I(int, int);
void letter_J(int, int);
void letter_K(int, int);
void letter_L(int, int);
void letter_M(int, int);
void letter_N(int, int);
void letter_O(int, int);
void letter_P(int, int);
void letter_Q(int, int);
void letter_R(int, int);
void letter_S(int, int);
void letter_T(int, int);
void letter_U(int, int);
void letter_V(int, int);
void letter_W(int, int);
void letter_X(int, int);
void letter_Y(int, int);
void letter_Z(int, int);

void number_0(int, int);
void number_1(int, int);
void number_2(int, int);
void number_3(int, int);
void number_4(int, int);
void number_5(int, int);
void number_6(int, int);
void number_7(int, int);
void number_8(int, int);
void number_9(int, int);
*/


character_function* get_array_of_characters(); 






