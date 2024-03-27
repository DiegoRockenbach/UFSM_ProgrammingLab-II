#include <stdio.h>

void imprime_matrizSimples(int m, int n, int *mat);

void populaMatrizSimples(int *mat, int linha, int coluna);

int* alocaMatrizSimples(int *linha, int *coluna);

void imprime_matrizPonteiros(int m, int n, int **mat);

void populaMatrizPonteiros(int **mat, int linha, int coluna);

int** alocaMatrizPonteiros(int *linha, int *coluna);

void desaloca_matriz (int m, int **mat);

int** alocaMatrizTamPredefPonteiros(int *linha, int *coluna);

int** soma_matriz(int m, int n, int** mat1, int** mat2);