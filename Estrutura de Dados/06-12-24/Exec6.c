#include <stdio.h>
#include <stdlib.h>
#include "functionsArvChar.c"

int main(){

  ArvoreChar *arvA, *arvB, *arvC, *arvD, *arvE, *arvF, *arvG, *arvH, *arvI, *arvJ;
  ArvoreChar *arvCopia;

  arvI = inicializaArvoreChar('I', NULL, NULL);
  arvG = inicializaArvoreChar('G', arvI, NULL);
  arvE = inicializaArvoreChar('E', arvG, NULL);

  arvJ = inicializaArvoreChar('J', NULL, NULL);
  arvH = inicializaArvoreChar('H', arvJ, NULL);
  arvF = inicializaArvoreChar('F', NULL, arvH);

  arvD = inicializaArvoreChar('D', arvE, arvF);
  arvC = inicializaArvoreChar('C', arvD, NULL);
  arvB = inicializaArvoreChar('B', NULL, arvC);
  arvA = inicializaArvoreChar('A', NULL, arvB);

  arvCopia = copiaArvoreChar(arvA);
  /* arvCopia->esq = inicializaArvoreChar('X', NULL, NULL); */ // descomenta pra ficar diferentes

  printf("\nConsidere a seguinte árvore descrita em pré-ordem (mesma do exercício 1):\n");
  imprimePercursoPreOrdem(arvA);
  printf("\nE também a seguinte árvore (também descrita em pré-ordem):\n");
  imprimePercursoPreOrdem(arvCopia);

  if (isArvoresEqual(arvA, arvCopia) == true){
    printf("\nAs duas árvores são IGUAIS; \n");
  }
  else {
    printf("\nAs duas árvores são DIFERENTES; \n");
  }
  


  printf("\n\n");

  system("pause");
  return 0;
}