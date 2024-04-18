#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Lista *no;

  no = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na lista:\n");
    scanf("%d", &insert);
    no = insereNo(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  printf("\nA lista possui %d elementos;\n", comprimento(no));
  imprimeLista(no);

  system("pause");
  return 0;
}