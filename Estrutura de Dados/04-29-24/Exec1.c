#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Pilha *no;

  no = inicializaPilha();
  while (stop != 1){
    printf("\nInsira um elemento à ser inserido na pilha: \n");
    scanf("%d", &insert);
    no = pushPilha(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  printf("\nA pilha inserida foi a seguinte: \n");
  imprimePilha(no);

  system("pause");
  return 0;
}