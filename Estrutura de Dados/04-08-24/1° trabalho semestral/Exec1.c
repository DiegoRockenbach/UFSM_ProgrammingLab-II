#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int i, iStr, jStr;
  Diagonal mat;

  printf("\nInsira a ordem da matriz: \n");
  scanf("%d", &mat.ordem);
  mat.v = alocaVetor(mat.ordem);
  printf("\nPreencha os valores da diagonal principal da matriz:\n");
  for (i = 0; i < mat.ordem; i++){
    printf("\nInsira o %d° elemento da diagonal principal: \n", i+1);
    scanf("%d", &mat.v[i]);
  }

  printf("\nA matriz inserida foi a seguinte: ");
  imprimeMatrizDiagonal(mat);

  printf("\nAgora, insira, respectivamente, a linha e a coluna de um elemento dentro dessa matriz para ele ser localizado: \n");
  scanf("%d %d", &iStr, &jStr);  
  if (iStr == jStr && (iStr < mat.ordem && jStr < mat.ordem)){
    printf("\nO elemento presente nas coordenadas inseridas é %d; \n\n", mat.v[iStr]);
  }
  else if (iStr >= mat.ordem || jStr >= mat.ordem){
    printf("\nAs coordenadas inseridas não estão localizadas na matriz; \n\n");
  }
  else {
    printf("\nO elemento presente nas coordenadas inseridas é 0; \n\n");
  }

  system("pause");
  return 0;
}