#include <stdio.h>
#include <stdlib.h>
#include "signatures.h"
#include "functions.c"

int main(){

  int linha, coluna;
  int *mat;

  mat = alocaMatrizSimples(&linha, &coluna);
  populaMatrizSimples(mat, linha, coluna);
  imprime_matrizSimples(linha, coluna, mat);

  free(mat);

  system("pause");
  return 0;

}