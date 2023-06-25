#include <stdio.h>
#include "run_test.h"

/*
int get_digit_number(int x){
  return 1;
}
*/

int main(void){

  run_test(1, get_digit_number(5), 1);
  /*
  run_test(2, get_digit_number(10), 2);
  */

  return 0;
}
