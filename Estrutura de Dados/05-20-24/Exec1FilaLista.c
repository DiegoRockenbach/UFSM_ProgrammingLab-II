#include <stdio.h>
#include <stdlib.h>
#include "functions_FilasLista.c"

int main(){

  int opcao, insert;
  FilaLista *fila;

  fila = (FilaLista*) malloc(sizeof(FilaLista));
  if (fila == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  fila = inicializaFilaLista(fila);
  fila->inicio = NULL;
  fila->fim = NULL;

  printf("\nSuponha uma fila vazia para ser preenchida...");
  
  while (1){
    printf("\n\nEscolha a opção desejada: \n");
    printf("\n1 - Inserir um elemento na fila;");
    printf("\n2 - Remover um elemento da fila;");
    printf("\n3 - Imprimir os elementos da fila;");
    printf("\n4 - Sair do programa;\n");
    scanf("%d", &opcao);

    if (opcao == 1){
      printf("\nQual elemento deseja inserir na fila? \n");
      scanf("%d", &insert);
      insereFilaLista(fila, insert);
    }
    else if (opcao == 2){
      popFilaLista(fila);
    }
    else if (opcao == 3){
      imprimeFilaLista(fila);
    }
    else if (opcao == 4){
      break;
    }

  }
  

  system("pause");
  return 0;
}