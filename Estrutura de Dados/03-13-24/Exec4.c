#include <stdio.h>
#include <stdlib.h>

void escreveOrdemCont (int n, int *vet){
  
  int i, iInverso;

  iInverso = n-1;

  printf("\n\n");

  for (i = 0; i < n; i++){

    printf("%d; ", vet[iInverso]);
    iInverso--;
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

  escreveOrdemCont (n, vet);

  free(vet);

  system ("pause");
  return 0;
}