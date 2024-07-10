#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions_MatrizAdj.c"

int main(){

  bool grafo[8][8];

  grafo[0][2] = true;
  grafo[0][3] = true;
  grafo[0][4] = true;
  grafo[0][5] = true;

  grafo[2][3] = true;
  
  grafo[3][1] = true;

  grafo[4][6] = true;

  grafo[5][2] = true;
  grafo[5][7] = true;

  grafo[7][0] = true;

  system("pause");
  return 0;
}