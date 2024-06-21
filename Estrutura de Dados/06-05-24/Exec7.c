#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int insert;

  printf("\nAlgoritmo de conversão entre dígitos decimais para binários unsigned: \n");

  while (1){
    printf("\nInsira um valor decimal natural a ser convertido: \n");
    scanf("%d", &insert);
    if (insert < 0){
      printf("\nValor inválido inserido! Favor inserir um valor maior que zero; \n");
    }
    else {
      break;
    }
  }
  
  printf("\nO número decimal %d, em binário, corresponde a ", insert);
  calculaBinario(insert);
  printf("\n(Ler da direita pra esquerda)\n\n");

  system("pause");
  return 0;
}