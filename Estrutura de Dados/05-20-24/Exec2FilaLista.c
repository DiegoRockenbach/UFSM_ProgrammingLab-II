#include <stdio.h>
#include <stdlib.h>
#include "functions_FilasLista.c"

int main(){

  FilaLista *f1, *f2, *f_res;

  f1 = (FilaLista*) malloc(sizeof(FilaLista));
  if (f1 == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f1 = inicializaFilaLista(f1);
  f1->inicio = NULL;
  f1->fim = NULL;

  f2 = (FilaLista *)malloc(sizeof(FilaLista));
  if (f2 == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f2 = inicializaFilaLista(f2);
  f2->inicio = NULL;
  f2->fim = NULL;

  f_res = (FilaLista*) malloc(sizeof(FilaLista));
  if (f_res == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f_res = inicializaFilaLista(f_res);
  f_res->inicio = NULL;
  f_res->fim = NULL;

  f1 = insereFilaLista(f1, 1);
  f1 = insereFilaLista(f1, 3);
  f1 = insereFilaLista(f1, 5);

  f2 = insereFilaLista(f2, 2);
  f2 = insereFilaLista(f2, 4);
  f2 = insereFilaLista(f2, 6);

  printf("\nAs filas estão da seguinte forma: \n\n");
  imprimeFilaLista(f1);
  imprimeFilaLista(f2);
  imprimeFilaLista(f_res);

  combinaFilasLista(f_res, f1, f2);

  printf("\nE após a transferência alternada de dados, elas ficaram da seguinte forma: \n\n");
  imprimeFilaLista(f1);
  imprimeFilaLista(f2);
  imprimeFilaLista(f_res);

  system("pause");
  return 0;
}