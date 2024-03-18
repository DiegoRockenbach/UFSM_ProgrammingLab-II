#include <stdio.h>
#include <stdlib.h>

int negativos (int n, float *vet){
  
  int i, quant = 0;

  for (i = 0; i < n; i++){
    if (vet[i] < 0){
      quant++;
    }
  }

  return quant;

}

int main(){

  int n, i;
  float *vet;

  printf("\nInsira quantos valores deseja armazenar em determinado vetor de números inteiros:\n");
  scanf("%d", &n);
  vet = (float*) malloc(n*sizeof(float));
  if (vet==NULL) {
    printf("Memória insuficiente.\n");
    return 1;
  }

  printf("\nAgora, popule o vetor:");

  for (i = 0; i < n; i++){
    printf("\nInsira um valor para a %d° posição do vetor:", i+1);
    scanf("%f", &vet[i]);
  }


  printf("\n\nNo vetor inserido, estão armazenados %d números negativos;\n\n", negativos (n, vet));

  free(vet);

  system ("pause");
  return 0;
}