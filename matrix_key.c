#include <REGX52.H>
#include "delay.h"

/* 
matrix key button structure:
-----------
7  8  9  +
4  5  6  -
1  2  3  *
0 clr =  /
-----------
*/
unsigned char scan_matrix_key() {
  unsigned char key_value = 'N';
  // check the certain key_button that is pressed
  P1 = 0xFF;
  P1_3 = 0;
  if (P1_7 == 0) {
    delay(20);
    while (P1_7 == 0) {
      delay(20);
      key_value = '7';
    }
  }
  if (P1_6 == 0) {
    delay(20);
    while (P1_6 == 0) {
      delay(20);
      key_value = '4';
    }
  }
  if (P1_5 == 0) {
    delay(20);
    while (P1_5 == 0) {
      delay(20);
      key_value = '1';
    }
  }
  if (P1_4 == 0) {
    delay(20);
    while (P1_4 == 0) {
      delay(20);
      key_value = '0';
    }
  }
  P1 = 0xFF;
  P1_2 = 0;
  if (P1_7 == 0) {
    delay(20);
    while (P1_7 == 0) {
      delay(20);
      key_value = '8';
    }
  }
  if (P1_6 == 0) {
    delay(20);
    while (P1_6 == 0) {
      delay(20);
      key_value = '5';
    }
  }
  if (P1_5 == 0) {
    delay(20);
    while (P1_5 == 0) {
      delay(20);
      key_value = '2';
    }
  }
  if (P1_4 == 0) {
    delay(20);
    while (P1_4 == 0) {
      delay(20);
      key_value = 'c';
    }
  }
  P1 = 0xFF;
  P1_1 = 0;
  if (P1_7 == 0) {
    delay(20);
    while (P1_7 == 0) {
      delay(20);
      key_value = '9';
    }
  }
  if (P1_6 == 0) {
    delay(20);
    while (P1_6 == 0) {
      delay(20);
      key_value = '6';
    }
  }
  if (P1_5 == 0) {
    delay(20);
    while (P1_5 == 0) {
      delay(20);
      key_value = '3';
    }
  }
  if (P1_4 == 0) {
    delay(20);
    while (P1_4 == 0) {
      delay(20);
      key_value = '=';
    }
  }
  P1 = 0xFF;
  P1_0 = 0;
  if (P1_7 == 0) {
    delay(20);
    while (P1_7 == 0) {
      delay(20);
      key_value = '+';
    }
  }
  if (P1_6 == 0) {
    delay(20);
    while (P1_6 == 0) {
      delay(20);
      key_value = '-';
    }
  }
  if (P1_5 == 0) {
    delay(20);
    while (P1_5 == 0) {
      delay(20);
      key_value = '*';
    }
  }
  if (P1_4 == 0) {
    delay(20);
    while (P1_4 == 0) {
      delay(20);
      key_value = '/';
    }
  }
  return key_value;
}