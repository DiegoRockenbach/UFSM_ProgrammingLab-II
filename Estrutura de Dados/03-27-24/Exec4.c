#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Lista *no1, *no2;

  no1 = inicializaLista();
  no2 = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na primeira lista:\n");
    scanf("%d", &insert);
    no1 = insereNo(no1, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  stop = 0;
  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na segunda lista:\n");
    scanf("%d", &insert);
    no2 = insereNo(no2, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  no1 = concatena(no1, no2);
  printf("\nAs listas concatenadas ficaram da seguinte forma:");
  imprimeLista(no1); // lembre-se que os elementos novos foram inseridos no início da lista, e não ao final

  system("pause");
  return 0;
}