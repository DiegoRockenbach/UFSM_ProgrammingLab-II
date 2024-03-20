#include <stdio.h>
#include <stdlib.h>
#include "signatures.h"
#include "functions.c"

int main(){

  int linha, coluna;
  int **mat;

  mat = alocaMatrizPonteiros(&linha, &coluna);
  populaMatrizPonteiros(mat, linha, coluna);
  imprime_matrizPonteiros(linha, coluna, mat);
  desaloca_matriz(linha, mat);

  system("pause");
  return 0;

}