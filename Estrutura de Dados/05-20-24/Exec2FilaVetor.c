#include <stdio.h>
#include <stdlib.h>
#include "functions_FilasVetor.c"

int main(){

  FilaVet *f1, *f2, *f_res;

  f1 = (FilaVet*) malloc(sizeof(FilaVet));
  if (f1 == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f1 = inicializaFilaVet(f1, 3);

  f2 = (FilaVet*) malloc(sizeof(FilaVet));
  if (f2 == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f2 = inicializaFilaVet(f2, 3);

  f_res = (FilaVet*) malloc(sizeof(FilaVet));
  if (f_res == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f_res = inicializaFilaVet(f_res, 6);

  f1->dados[0] = 1;
  f1->dados[1] = 3;
  f1->dados[2] = 5;
  f1->fim = 2;

  f2->dados[0] = 2;
  f2->dados[1] = 4;
  f2->dados[2] = 6;
  f2->fim = 2;

  printf("\nAs filas estão da seguinte forma: \n\n");
  imprimeFilaVet(f1, 3);
  imprimeFilaVet(f2, 3);
  imprimeFilaVet(f_res, 6);

  combinaFilasVet(f_res, f1, f2);

  printf("\nE após a transferência alternada de dados, elas ficaram da seguinte forma: \n\n");
  imprimeFilaVet(f1, 3);
  imprimeFilaVet(f2, 3);
  imprimeFilaVet(f_res, 6);

  system("pause");
  return 0;
}