#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main () {

    int ***mat;
    int m, n, z; // m = linhas, n = colunas, z = profundidade
    //input dimensões da matriz
    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);
    printf("Digite o numero da profundidade: ");
    scanf("%d", &z);
    printf("\n");
    //as operações solicitadas no  trabalho
    mat = aloca_matriz(m,n,z); 
    preenche_matriz(m,n,z,mat);
    imprime_matriz(m,n,z,mat);
 
    //libera memória matriz
    libera_matriz(m,n,mat);

    system("pause");
    return 0;
}