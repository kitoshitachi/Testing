#include <stdio.h>
#include <string.h>

int main(void){
  int a, b, c, d, i;
  int x[16];
  char y[17];

  printf("[radix conversion]\n");
  printf(" 1) Dec --> Bin\n");
  printf(" 2) Bin --> Dec\n");
  printf("\n");
  printf("Select 1 or 2\n> ");
  scanf("%d", &a);

  if ( a == 1 ){
    printf("\n 1) Dec --> Bin\n\n");
    printf("Input decimal number\n> ");
    scanf("%d", &b);
    if ( b < 0 || b > 65535 ){
      printf("[ERROR] invalid decimal number\n");
      return 1;
    }

    printf("Convert it to binary number\n\n");
    i = 0;
    c = b;
    do{
      x[i] = c % 2;
      c /= 2;
      i++;
    }
    while ( c > 0 );

    printf(" %d --> ", b);
    do {
      i--;
      printf("%d", x[i]);
    }
    while( i > 0 );
    printf("\n");
  }
  else if ( a == 2 ){
    printf("\n 2) Bin --> Dec\n\n");
    printf("Input binary number\n> ");
    scanf("%s", y);
    if ( (int)strlen(y) > 16 ){
      printf("[ERROR] too long binary number\n");
      return 1;
    }

    printf("Convert it to decimal number\n\n");
    d = 0;
    for ( i = 0; i < (int)strlen(y); i++ ){
      d *= 2;
      if ( y[i] == '1' ){
        d += 1;
      }
      else if ( y[i] == '0' ){
        d += 0;
      }
      else{
        printf("[ERROR] invalid binary number\n");
        return 1;
      }
    }

    printf(" %s --> %d\n", y, d);
  }
  else{
    printf("[ERROR] invalid number\n");
    return 1;
  }

  return 0;
}
