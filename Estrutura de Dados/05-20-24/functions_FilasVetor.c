#include <stdio.h>
#include <stdlib.h>

struct fila_t{
  int dados[10];
  int inicio;
  int fim;
}; typedef struct fila_t FilaVet;

FilaVet* inicializaFilaVet(FilaVet *fila, int tam){

  int i;

  fila->inicio = 0;
  fila->fim = 0;

  for (i = 0; i < tam; i++){
    fila->dados[i] = 0;
  }

  return fila;
}

void insereFilaVet(FilaVet *fila, int tam, int insert){

  if(fila->fim == tam-1){
    if (fila->inicio > 0){
      fila->fim = 0;
      fila->dados[fila->fim] = insert;
    }
    else {
      printf("\nA fila está cheia e não é possível inserir mais elementos até remover elementos já preenchidos; \n");
    }
  }
  else {
    if (fila->inicio == fila->fim && fila->dados[0] == 0){
      fila->dados[fila->fim] = insert;
    }
    else {
      fila->fim++;
      fila->dados[fila->fim] = insert;
    }
  }
}

void popFilaVet(FilaVet *fila){

  if (fila->inicio == fila->fim && fila->dados[0] == 0){
    printf("\nA fila já está vazia, portanto, não foi possível retirar elementos");
  }
  else {
    fila->dados[fila->inicio] = 0;
    fila->inicio++;
  }
  
}

void imprimeFilaVet(FilaVet *fila, int tam){

  int i;

  i = fila->inicio;
  if (fila->inicio == fila->fim && fila->dados[0] == 0){
    printf("Não há elementos na lista a serem imprimidos; \n");
  }
  else if (fila->inicio == fila->fim && fila->dados[0] != 0){
    printf("[%d]; ", fila->dados[i]);
  }
  else {
    while (i != fila->fim){
      printf("[%d]; ", fila->dados[i]);
      if (i == tam-1){
        i = 0;
      }
      else {
        i++;
      }
    }
    printf("[%d]; ", fila->dados[i]);
  }

  printf("\n\n");
}

void combinaFilasVet(FilaVet *f_res, FilaVet *f1, FilaVet *f2){

  int i = 0, j = 0, k, count = 1;  // count sempre flutua entre 1 e 2, que é o que define se o valor que vai pra f_res é de f1 ou f2

  for (k = 0; k < 6; k++){
    if (count == 1){
      insereFilaVet(f_res, 6, f1->dados[i]);
      popFilaVet(f1);
      i++;
      count++;
    }
    else if (count == 2){
      insereFilaVet(f_res, 6, f2->dados[j]);
      popFilaVet(f2);
      j++;
      count--;
    }
  }

}