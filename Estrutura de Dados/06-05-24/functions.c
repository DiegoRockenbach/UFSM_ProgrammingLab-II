#include <stdio.h>
#include <stdlib.h>

int calculaFatorial(int n){ // int produto (int  n);

  if (n == 0){    
    return 1;
  }
  else {
    return n*calculaFatorial(n-1);
  }

}

void imprimeIntIntervalo(int min, int max){

  if (min == max){
    printf("%d; ", max);
  }
  else{
    printf("%d; ", min);
    imprimeIntIntervalo(min+1, max);
  }

}

float calculaPotencia(float base, float potencia){

  if (potencia == 0){
    return 1;
  }
  else if (base == 0){
    return 0;
  }
  else {
    return base*calculaPotencia(base, potencia-1);
  }

}

float calculaS(float up, float down){ // up = dividendo, down = divisor

  if (up == 99 && down == 50){
    return up/down;
  }
  else {
    return (up/down)+calculaS(up+2, down+1);
  }

}

int calculaSoma(int maior, int menor){

  if (menor == 0){
    return maior;
  }
  else {
    return calculaSoma(maior+1, menor-1); // x+1 = sucessor; x-1 = predecessor;
  }

}

int pesquisaBinaria(int vet[], int search, int esq, int dir){

  int meio;
  
  meio = (esq + dir)/2;

  if (search == vet[meio]){
    return meio;
  }
  if (esq < 9 && dir > 0){
    if (search < vet[meio]){
      dir = meio;
      return pesquisaBinaria(vet, search, esq, dir);
    }
    else if (search > vet[meio]){
      esq = meio;
      return pesquisaBinaria(vet, search, esq, dir);
    }
  }
  
  return -1;
}

void calculaBinario(int dividendo){

  if (dividendo == 1){
    printf("1");
  }
  else if (dividendo%2 == 0){
    printf("0");
    calculaBinario(dividendo/2);
  }
  else if (dividendo%2 == 1){
    printf("1");
    calculaBinario(dividendo/2);
  }
}