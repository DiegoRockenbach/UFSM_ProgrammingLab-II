#include <stdio.h>
#include <stdlib.h>

void inverte (int n, int *vet){
  
  int i, iInverso, temp;

  iInverso = n-1;

  printf("\n\nO vetor inserido foi:\n");

  for (i = 0; i < n; i++){
    printf("%d° valor: %d;\n", i+1, vet[i]);
  }

  for (i = 0; i < n/2; i++){
    temp = vet[i];
    vet[i] = vet[iInverso];
    vet[iInverso] = temp;
    iInverso--;
  }

  printf("\nE, após a inversão, o vetor ficou da seguinte forma:\n");

  for (i = 0; i < n; i++){
    printf("%d° valor: %d;\n", i+1, vet[i]);
  }

  printf("\n\n");

}

int main(){

  int n, i, *vet;

  printf("\nInsira quantos valores deseja armazenar em determinado vetor de números inteiros:\n");
  scanf("%d", &n);
  vet = (int*) malloc(n*sizeof(int));
  if (vet==NULL) {
    printf("Memória insuficiente.\n");
    return 1;
  }

  printf("\nAgora, popule o vetor:\n");

  for (i = 0; i < n; i++){
    printf("\nInsira um valor para a %d° posição do vetor:", i+1);
    scanf("%d", &vet[i]);
  }

  inverte (n, vet);

  free(vet);

  system ("pause");
  return 0;
}