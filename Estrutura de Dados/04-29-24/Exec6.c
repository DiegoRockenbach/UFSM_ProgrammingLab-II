#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Pilha *p1, *p2;

  p1 = inicializaPilha();
  while (stop != 1){
    printf("\nInsira um elemento à ser inserido na primeira pilha: \n");
    scanf("%d", &insert);
    p1 = pushPilha(p1, insert);
    printf("\nDeseja encerrar a inserção da primeira pilha? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  stop = 0;
  p2 = inicializaPilha();
  printf("\n\nAgora, para a inserção da segunda pilha: \n");
  while (stop != 1){
    printf("\nInsira um elemento à ser inserido na segunda pilha: \n");
    scanf("%d", &insert);
    p2 = pushPilha(p2, insert);
    printf("\nDeseja encerrar a inserção da segunda pilha? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  printf("\nA primeira pilha inserida (p1) foi a seguinte: \n");
  imprimePilha(p1);
  printf("\nE a segunda pilha inserida (p2) foi a seguinte: \n");
  imprimePilha(p2);
  
  p1 = concatenaPilhas(p1, p2);

  printf("\nE, após concatenadas, as pilhas ficaram assim: \n");
  imprimePilha(p1);
  imprimePilha(p2); // foi esvaziada

  system("pause");
  return 0;
}