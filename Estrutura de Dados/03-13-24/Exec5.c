#include <stdio.h>
#include <stdlib.h>

void alocaVet (int n, float *vet){

  vet = (float*) malloc(n*sizeof(float));
  if (vet==NULL) {
    printf("Memória insuficiente.\n");
    return 1;
  }

}

void populaVet (int n, float *vet){

  int i;

  printf("\nAgora, popule o vetor:\n");

  for (i = 0; i < n; i++){
    printf("\nInsira um valor para a %d° posição do vetor:", i+1);
    scanf("%f", &vet[i]);
  }

}

void calculaMedia (int n, float *vet, float *media){

  int i;

  for (i = 0; i < n; i++){
    if (*media == 0){
      *media = vet[i];
    }
    else {
      *media = *media+vet[i];
    }
  }
  *media = *media/n;

}

void percValMaiorMedia (int n, float *vet, float media, float *percMaior){

  int i, quantMaior = 0;

  for (i = 0; i < n; i++){
    if (vet[i] > media){
      quantMaior++;
    }
  }
  *percMaior = (quantMaior*100)/n;

}

int main(){

  int n, i;
  float *vet, media = 0, percMaior;

  printf("\nInsira quantos valores deseja armazenar em determinado vetor de números inteiros:\n");
  scanf("%d", &n);

  alocaVet(n, vet);
  populaVet(n, vet);
  calculaMedia(n, vet, &media);
  percValMaiorMedia(n, vet, media, &percMaior);
  
  printf("\n\nO vetor inserido foi:\n");

  for (i = 0; i < n; i++){
    printf("%d° valor: %.2f;\n", i+1, vet[i]);
  }

  free(vet);

  printf("\nE %.f%% de seus valores são maiores que a média de seus valores, que é %.2f;\n\n", percMaior, media);

  system ("pause");
  return 0;
}