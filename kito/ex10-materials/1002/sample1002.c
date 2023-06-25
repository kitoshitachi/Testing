#include <stdio.h>
#include <string.h>

int main(void){
  int option, user_decimal, temp_dec_bin, temp_bin_dec, i;
  int binary[16];
  char user_binary[17];

  printf("[radix conversion]\n");
  printf(" 1) Dec --> Bin\n");
  printf(" 2) Bin --> Dec\n");
  printf("\n");
  printf("Select 1 or 2\n> ");
  scanf("%d", &option);

  if ( option == 1 ){
    printf("\n 1) Dec --> Bin\n\n");
    printf("Input decimal number\n> ");
    scanf("%d", &user_decimal);
    if ( user_decimal < 0 || user_decimal > 65535 ){
      printf("[ERROR] invalid decimal number\n");
      return 1;
    }

    printf("Convert it to binary number\n\n");
    i = 0;
    temp_dec_bin = user_decimal;
    do{
      binary[i] = temp_dec_bin % 2;
      temp_dec_bin /= 2;
      i++;
    }
    while ( temp_dec_bin > 0 );

    printf(" %d --> ", user_decimal);
    do {
      i--;
      printf("%d", binary[i]);
    }
    while( i > 0 );
    printf("\n");
  }
  else if ( option == 2 ){
    printf("\n 2) Bin --> Dec\n\n");
    printf("Input binary number\n> ");
    scanf("%s", user_binary);
    if ( (int)strlen(user_binary) > 16 ){
      printf("[ERROR] too long binary number\n");
      return 1;
    }

    printf("Convert it to decimal number\n\n");
    temp_bin_dec = 0;
    for ( i = 0; i < (int)strlen(user_binary); i++ ){
      temp_bin_dec *= 2;
      if ( user_binary[i] == '1' ){
        temp_bin_dec += 1;
      }
      else if ( user_binary[i] == '0' ){
        temp_bin_dec += 0;
      }
      else{
        printf("[ERROR] invalid binary number\n");
        return 1;
      }
    }

    printf(" %s --> %d\n", user_binary, temp_bin_dec);
  }
  else{
    printf("[ERROR] invalid number\n");
    return 1;
  }

  return 0;
}
