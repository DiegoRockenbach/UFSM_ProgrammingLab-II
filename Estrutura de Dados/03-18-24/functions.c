#include <stdio.h>
#include <stdlib.h>
#include "signatures.h"

//  EXEC_4

int** soma_matriz(int m, int n, int** mat1, int** mat2){

  int i, j;
  int **matSoma;

  matSoma = alocaMatrizTamPredefPonteiros(&m, &n);  // daria também pra sobrescrever a mat1/mat2 com a soma das duas

  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      matSoma[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  
  return matSoma;

}

int** alocaMatrizTamPredefPonteiros(int *linha, int *coluna){

  int i;
  int **mat;

  mat = (int**)malloc(*linha * sizeof(int*));
  if (mat == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  for (i = 0; i < *linha; i++){
    mat[i] = (int*)malloc(*coluna * sizeof(int));
    if (mat[i] == NULL){
      printf("\nErro de alocação de memória!\n\n");
      system("pause");
      return NULL;
    }
  }

  return mat;

}

//  EXEC_3

void desaloca_matriz(int m, int **mat){

  int i;

  for (i = 0; i < m; i++){
    free(mat[i]);
  }
  free (mat);

}

//  EXEC_2

int** alocaMatrizPonteiros(int *linha, int *coluna){

  int i;
  int **mat;

  printf("\nInsira os valores L e C que serão, respectivamente, as linhas e colunas de determinada matriz alocada dinamicamente como vetor de ponteiros: \n");
  scanf("%d %d", &*linha, &*coluna);

  mat = (int**)malloc(*linha * sizeof(int*));
  if (mat == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  for (i = 0; i < *linha; i++){
    mat[i] = (int*)malloc(*coluna * sizeof(int));
    if (mat[i] == NULL){
      printf("\nErro de alocação de memória!\n\n");
      system("pause");
      return NULL;
    }
  }

  return mat;

}

void populaMatrizPonteiros(int **mat, int linha, int coluna){

  int i, j;

  for (i = 0; i < linha; i++){
    for (j = 0; j < coluna; j++){
      printf("\nInsira um valor para armazenar na linha %d, coluna %d da matriz: \n", i, j);
      scanf("%d", &mat[i][j]);
    }
  }

}

void imprime_matrizPonteiros(int m, int n, int **mat){

  int i, j;

  printf("\nA matriz inserida foi a seguinte: \n");
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

}

//  EXEC_1

int* alocaMatrizSimples(int *linha, int *coluna){

  int *mat;

  printf("\nInsira os valores L e C que serão, respectivamente, as linhas e colunas de determinada matriz alocada dinamicamente como vetor simples: \n");
  scanf("%d %d", &*linha, &*coluna);

  mat = (int*)malloc(*linha * *coluna * sizeof(int));
  if (mat == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }

  return mat;

}

void populaMatrizSimples(int *mat, int linha, int coluna){

  int i, j;

  for (i = 0; i < linha; i++){
    for (j = 0; j < coluna; j++){
      printf("\nInsira um valor para armazenar na linha %d, coluna %d da matriz: \n", i, j);
      scanf("%d", &mat[i*coluna+j]);
    }
  }

}

void imprime_matrizSimples(int m, int n, int *mat){

  int i, j;

  printf("\nA matriz inserida foi a seguinte: \n");
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      printf("%d ", mat[i*n+j]);
    }
    printf("\n");
  }

}