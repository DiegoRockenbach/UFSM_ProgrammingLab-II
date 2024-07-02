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

  printf("\nConsidere a seguinte árvore descrita em pré-ordem (mesma do exercício 1):\n");
  imprimePercursoPreOrdem(arvA);
  printf("\nNesta árvore, há %d \"nós folha\" (nós sem nenhum filho); \n\n", contaLeafNodes(arvA));

  system("pause");
  return 0;
}