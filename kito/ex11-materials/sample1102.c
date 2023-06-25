#include <stdio.h>
#include "run_test.h"

int charge(int order, int member, int sale)
{
  if (order <= 0 || order >= 1000000)
  {
    // printf("order is invalid.");
    return -1;
  }

  switch (sale)
  {
  case 0:
    break;
  case 1:
    order = order * 90 / 100;
    break;
  case 2:
    order = order * 70 / 100;
    break;
  default:
    // printf("sale is invalid.");
    return -1;
  }

  switch (member)
  {
  case 0:
    if (order < 2000)
      return order + 410;

  case 1:
    return order;

  default:
    // printf("member is invalid.");
    return -1;
  }
}

int main(void)
{

  //test error
  //order
  run_test(0, charge(0, 0, 0), -1);
  run_test(1, charge(1000000, 0, 0), -1);
  // member
  run_test(2, charge(1, 2, 0), -1); 
  run_test(3, charge(1, -1, 0), -1); 
  // sale
  run_test(4, charge(1, 0, 3), -1); 
  run_test(5, charge(1, 0, -1), -1); 

  //no error
  //premium
  run_test(6, charge(1, 1, 0), 1);
  run_test(7, charge(1100, 1, 0), 1100);
  run_test(8, charge(999999, 1, 0), 999999);

  run_test(9, charge(1, 1, 1), 0);
  run_test(10, charge(10, 1, 1), 9);
  run_test(11, charge(3, 1, 1), 2);
  run_test(12, charge(7, 1, 1), 6);
  run_test(13, charge(2000, 1, 1), 1800);
  run_test(14, charge(4000, 1, 1), 3600);

  run_test(15, charge(1, 1, 2), 0);
  run_test(16, charge(10, 1, 2), 7);
  run_test(17, charge(3, 1, 2), 2);
  run_test(18, charge(7, 1, 2), 4);
  run_test(19, charge(2000, 1, 2), 1400);
  run_test(20, charge(4000, 1, 2), 2800);


  // normal
  run_test(21, charge(1, 0, 0), 411);
  run_test(22, charge(1, 0, 1), 410);
  run_test(23, charge(1, 0, 2), 410);

  run_test(24, charge(2223, 0, 1), 2000);
  run_test(25, charge(2223, 0, 2), 1966);

  run_test(26, charge(2222, 0, 1), 2409);
  run_test(27, charge(2856, 0, 2), 2409);

  return 0;
}
