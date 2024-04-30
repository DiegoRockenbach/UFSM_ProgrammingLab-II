#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int i, j, infoInsert;
  Identidade *mat;
  Lista *no;

  mat = NULL;
  mat = alocaMatrizIdentidade(mat);
  no = inicializaLista();

  printf("\nInsira a ordem da matriz: \n");
  scanf("%d", &mat->ordem);

  printf("\nPreencha os valores da matriz:\n");
  for (i = 0; i < mat->ordem; i++){
    for (j = 0; j < mat->ordem; j++){
      printf("\nInsira o elemento localizado nas coordenadas [%d][%d]: \n", i, j);
      scanf("%d", &infoInsert);
      no = insereNoFinal(no, infoInsert, i, j);
    }
  }

  mat->prim = no;
  imprimeMatrizIdentidade(mat);
  verificaMatrizIdentidade(mat);

  system("pause");
  return 0;
}