#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int n, res;

  while (1){
    printf("\nInsira um número natural para seu fatorial ser calculado: \n");
    scanf("%d", &n);
    if (n < 0){
      printf("\nInsira um número natural para seu fatorial ser calculado: \n");
      scanf("%d", &n);
    }
    else {
      break;
    }
  }

  res = calculaFatorial(n);
  printf("\nO fatorial de %d é %d; \n", n, res);

  system("pause");
  return 0;
}