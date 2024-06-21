#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int i, search, vet[10], res;

  printf("\nAlgoritmo que realiza a busca binária em um vetor de 10 posições utilizando funções recursivas; \n");

  printf("\nConsidere o seguinte vetor: \n");
  for (i = 0; i < 10; i++){
    vet[i] = i+1;
    printf("[%d]; ", vet[i]);
  }

  printf("\nQual número deseja buscar dentro dele? (o retorno será sua posição dentro do vetor, e -1 se não for encontrado) \n");
  scanf("%d", &search);

  printf("\nO retorno da função é: %d; \n\n", res = pesquisaBinaria(vet, search, -1, 10));

  system("pause");
  return 0;
}