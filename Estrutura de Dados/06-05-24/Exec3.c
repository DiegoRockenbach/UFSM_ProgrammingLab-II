#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  float base, potencia, resultado;

  printf("\nAlgoritmo que calcula X^n; \n\n");

  while (1){
    printf("\nInsira a base X: \n");
    scanf("%f", &base);
    printf("\nInsira a potência N: \n");
    scanf("%f", &potencia);
    if (base < 0 || potencia < 0){
      printf("\nValores inválidos inseridos, favor inserir valores positivos; \n");
      continue;
    }
    else {
      break;
    }
  }
  
  resultado = calculaPotencia(base, potencia);
  printf("\n%.2f^%.2f = %.2f; \n\n", base, potencia, resultado);

  system("pause");
  return 0;
}