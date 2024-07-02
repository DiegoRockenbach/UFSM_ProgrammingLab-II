#include <stdio.h>
#include <stdlib.h>
#include "functionsArvChar.c"

int main(){

  ArvoreChar *arvA, *arvB, *arvC, *arvD, *arvE, *arvF, *arvG, *arvH, *arvI, *arvJ;

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

  printf("\nImpressão da árvore em questão de acordo com o percurso pré ordem: (pai->esq->dir)\n");
  imprimePercursoPreOrdem(arvA);

  printf("\n\nImpressão da árvore em questão de acordo com o percurso pós ordem: (esq->dir->pai)\n");
  imprimePercursoPosOrdem(arvA);

  printf("\n\nImpressão da árvore em questão de acordo com o percurso de ordem simétrica: (esq->pai->dir)\n");
  imprimePercursoOrdemSimetrica(arvA);

  printf("\n\n");

  system("pause");
  return 0;
}