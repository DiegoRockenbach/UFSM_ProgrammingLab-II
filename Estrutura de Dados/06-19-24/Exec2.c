#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  Arvore *abb = NULL;

  abb = insereNoABB(abb, 5);
  abb = insereNoABB(abb, 1);
  abb = insereNoABB(abb, 3);
  abb = insereNoABB(abb, 4);
  abb = insereNoABB(abb, 7);
  abb = insereNoABB(abb, 2);
  abb = insereNoABB(abb, 8);
  abb = insereNoABB(abb, 8);
  abb = insereNoABB(abb, 1);
  abb = insereNoABB(abb, 5);
  abb = insereNoABB(abb, 4);
  printf("\nConsidere a seguinte árvore binária de busca (a mesma do exercício 1): \n");
  imprimeABBCrescente(abb);
  printf("\n\nÉ deste modo que ela fica em ordem decrescente: \n");
  imprimeABBDecrescente(abb);

  system("pause");
  return 0;
}