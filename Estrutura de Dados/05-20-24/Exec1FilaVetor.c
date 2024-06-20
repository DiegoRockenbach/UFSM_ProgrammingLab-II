#include <stdio.h>
#include <stdlib.h>
#include "functions_FilasVetor.c"

int main(){

  int opcao, insert;
  FilaVet *fila;

  fila = (FilaVet*) malloc(sizeof(FilaVet));
  if (fila == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  fila = inicializaFilaVet(fila, 10);

  printf("\nSuponha uma fila com 10 espaços vazios a serem preenchidos...");
  
  while (1){
    printf("\nEscolha a opção desejada: \n");
    printf("\n1 - Inserir um elemento na fila;");
    printf("\n2 - Remover um elemento da fila;");
    printf("\n3 - Imprimir os elementos da fila;");
    printf("\n4 - Sair do programa;\n");
    scanf("%d", &opcao);

    if (opcao == 1){
      printf("\nQual elemento deseja inserir na fila? \n");
      scanf("%d", &insert);
      insereFilaVet(fila, 10, insert);
    }
    else if (opcao == 2){
      popFilaVet(fila);
    }
    else if (opcao == 3){
      printf("\n\n");
      imprimeFilaVet(fila, 10);
    }
    else if (opcao == 4){
      break;
    }

  }
  

  system("pause");
  return 0;
}