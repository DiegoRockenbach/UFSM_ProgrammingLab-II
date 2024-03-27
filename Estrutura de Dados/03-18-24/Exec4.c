#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main(){

  int linha, coluna;
  int **mat1, **mat2, **matSoma;

  mat1 = alocaMatrizPonteiros(&linha, &coluna);
  mat2 = alocaMatrizTamPredefPonteiros(&linha, &coluna);
  printf("\nInsira valores para popular a primeira matriz: \n");
  populaMatrizPonteiros(mat1, linha, coluna);
  printf("\nInsira valores para popular a segunda matriz: \n");
  populaMatrizPonteiros(mat2, linha, coluna);
  printf("\nO conteúdo inserido na primeira matriz é o seguinte: \n");
  imprime_matrizPonteiros(linha, coluna, mat1);
  printf("\nO conteúdo inserido na segunda matriz é o seguinte: \n");
  imprime_matrizPonteiros(linha, coluna, mat2);
  matSoma = soma_matriz (linha, coluna, mat1, mat2);
  printf("\nE o conteúdo na matrizSoma, que corresponde a soma das duas matrizes previamente inseridas é o seguinte: \n");
  imprime_matrizPonteiros(linha, coluna, matSoma);
  desaloca_matriz(linha, mat1);
  desaloca_matriz(linha, mat2);
  desaloca_matriz(linha, matSoma);

  system("pause");
  return 0;

}