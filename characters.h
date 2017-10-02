#include <stdio.h>
#include <stdlib.h>


#define DELAY 75
#define LIGHTS 112
#define NUMBER_CHARACTERS 36
#define NUMBER_COLUMNS 13  // 0 indexed


typedef int* (*character_function)(int);


int converter(int);
int pinner(int);

void initialize_setup();
//void all_off();
//void all_on();

//void cycle_all();
//void cycle_characters(character_function*);

void Character_leds_init();
void Character_leds_destroy();

void validate_light(int);

int* Special_SPACE(int);
int* Special_EXCLAMATION(int);
int* Special_QOUTE(int);
int* Special_HASHTAG(int);
int* Special_QWERTY(int);
int* Special_MOD(int);
int* Special_AND(int);
int* Special_Apostrophe(int);
int* Special_LEFT_PAREN(int);
int* Special_RIGHT_PAREN(int);
int* Special_STAR(int);
int* Special_PLUS(int);
int* Special_COMMA(int);
int* Special_MINUS(int);
int* Special_PERIOD(int);
int* Special_FOR_SLASH(int);

int* number_0(int);
int* number_1(int);
int* number_2(int);
int* number_3(int);
int* number_4(int);
int* number_5(int);
int* number_6(int);
int* number_7(int);
int* number_8(int);
int* number_9(int);

int* Special_COLON(int);
int* Special_SEMI_COLON(int);
int* Special_LEFT_CARET(int);
int* Special_EQUAL(int);
int* Special_RIGHT_CARET(int);
int* Special_QUESTION(int);
int* Special_AT(int);

int* letter_A(int);
int* letter_B(int);
int* letter_C(int);
int* letter_D(int);
int* letter_E(int);
int* letter_F(int);
int* letter_G(int);
int* letter_H(int);
int* letter_I(int);
int* letter_J(int);
int* letter_K(int);
int* letter_L(int);
int* letter_M(int);
int* letter_N(int);
int* letter_O(int);
int* letter_P(int);
int* letter_Q(int);
int* letter_R(int);
int* letter_S(int);
int* letter_T(int);
int* letter_U(int);
int* letter_V(int);
int* letter_W(int);
int* letter_X(int);
int* letter_Y(int);
int* letter_Z(int);


int* Special_LEFT_BRACKET(int);
int* Special_BACK_SLASH(int);
int* Special_RIGHT_BRACKET(int);
int* Special_UP_CARET(int);
int* Special_UNDERSCORE(int);
int* Special_BACK_TIC(int);

// After this we need to do more math to make the array linear
int* Special_LEFT_CURLY_BRACE(int);
int* Special_VERTICAL_BAR(int);
int* Special_RIGHT_CURLY_BRACE(int);
int* Special_TILDA(int);


character_function* get_array_of_characters(); 






