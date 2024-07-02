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

  printf("\nConsidere a seguinte árvore descrita em pré-ordem (mesma do exercício 1):\n");
  imprimePercursoPreOrdem(arvA);
  printf("\nE então sua cópia, também descrita em pré-ordem:\n");
  imprimePercursoPreOrdem(arvCopia);


  printf("\n\n");

  system("pause");
  return 0;
}