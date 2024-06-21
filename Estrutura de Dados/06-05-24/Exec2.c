#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int min, max;

  printf("\nAlgoritmo que imprime números inteiros dentro de um intervalo informado; \n\n");

  while (1){
    printf("\nInsira o teto (valor máximo) do intervalo: \n");
    scanf("%d", &max);
    printf("\nInsira o chão (valor mínimo) do intervalo: \n");
    scanf("%d", &min);
    if (max <= min){
      printf("\nValores inválidos inseridos; \n");
      continue;
    }
    else {
      break;
    }
  }

  imprimeIntIntervalo(min, max);
  printf("\n\n");

  system("pause");
  return 0;
}