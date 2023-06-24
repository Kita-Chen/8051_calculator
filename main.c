#include <CTYPE.H>
#include <REGX52.H>

#include "LCD1602.h"
#include "delay.h"
#include "matrix_key.h"
#include "port_name.h"

/*
matrix key button structure:
-----------
7  8  9  +
4  5  6  -
1  2  3  *
0 clr =  /
-----------
*/

void calculate_clear(int *count_size, int *scan_index, int *answer,
                     int *calculate_buf, unsigned char *operator_state,
                     unsigned char *equal_state, unsigned char *count_buf) {
  int i;
  *count_size = 0;
  *scan_index = 1;
  *answer = 0;
  *calculate_buf = 0;
  *operator_state = '+';
  *equal_state = 0;
  for (i = 0; i <= 15; i++) {
    count_buf[i] = ' ';
  }
  LCD_ShowString(2, 1, "     ");
}

void main() {
  unsigned char press_key;
  unsigned char count_buf[16] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  int count_size = 0;
  int scan_index;
  int answer = 0;
  int calculate_buf = 0;
  unsigned char operator_state = '+';
  unsigned char equal_state = 0;
  LCD_Init();
  while (1) {
    press_key = scan_matrix_key();
    if (press_key == 'c') {
      calculate_clear(&count_size, &scan_index, &answer, &calculate_buf,
                      &operator_state, &equal_state, count_buf);
    } else if (press_key != 'N') {
      // store the key value into buffer that will be shown on LCD
      count_buf[count_size] = press_key;
      count_size++;
      // check if press key is digit
      if (isdigit(press_key)) {
        calculate_buf = calculate_buf * 10 + (press_key - '0');
      } else {
        // judge the operator is add, subtract, multiply, or divide
        if (operator_state == '+') {
          answer += calculate_buf;
        } else if (operator_state == '-') {
          answer -= calculate_buf;
        } else if (operator_state == '*') {
          answer *= calculate_buf;
        } else if (operator_state == '/') {
          answer /= calculate_buf;
        }
        operator_state = press_key;
        calculate_buf = 0;
        if (operator_state == '=') {
          equal_state = 1;
        }
      }
    }
    for (scan_index = 1; scan_index <= 16; scan_index++) {
      LCD_ShowChar(1, scan_index, count_buf[scan_index - 1]);
      if (equal_state) {
        LCD_ShowNum(2, 1, answer, 5);
      }
    }
  }
}
