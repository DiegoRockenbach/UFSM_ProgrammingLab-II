#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  Arvore *abb = NULL;

  abb = insereNoABB(abb, 5);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 1);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 3);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 4);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 7);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 2);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 8);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 8);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 1);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 5);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);
  abb = insereNoABB(abb, 4);
  printf("\nA árvore está do seguinte modo: \n");
  imprimeABBCrescente(abb);

  printf("\n\n");

  system("pause");
  return 0;
}