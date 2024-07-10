#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

imprimeGrafoMatriz(bool **matriz, int tam){
  
  int i, j;
  bool flag = false;

  for (i = 0; i < tam; i++){
    printf("\nO número %d aponta para: ", i);
    for (j = 0; j < tam; j++){
      if (matriz[i][j] == true){
        printf("[%d]; ", j);
        flag = true;
      }
    }
  }

}

inicializaGrafoMatriz(bool **matriz, int tam){

  int i, j;

  for (i = 0; i < tam; i++){
    for (j = 0; j < tam; j++){
      matriz[i][j] = false;
    }
  }
  
}