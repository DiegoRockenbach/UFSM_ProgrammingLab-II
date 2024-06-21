#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int x, y, temp = 0;

  printf("\nAlgoritmo que calcula a soma de dois números sem usar nenhuma operação de adição; \n");

  printf("\nInsira um valor positivo X: \n");
  scanf("%d", &x);
  printf("\nAgora, insira um valor positivo Y, menor que X: \n");
  scanf("%d", &y);

  if (y > x){ // certifica de que x > y
    temp = y;
    y = x;
    x = temp;
  }

  printf("\n%d + %d = %d; \n", x, y, calculaSoma(x, y));

  system("pause");
  return 0;
}