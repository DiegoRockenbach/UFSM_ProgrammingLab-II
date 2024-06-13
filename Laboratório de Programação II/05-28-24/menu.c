#include <stdio.h>
#include <stdlib.h>

int imprimeMenu(){

  int opcao;

  printf("\n\nEscolha uma das seguintes opções: \n\n");
  printf("1 - Inserir aluno na fila normal; \n");
  printf("2 - Inserir aluno na fila prioritária; \n");
  printf("3 - Fundir duas filas na fila interna (única, de 10 posições); \n");
  printf("4 - Repor bandejas; \n");
  printf("5 - Retirar bandeja pelo aluno da fila única; \n");
  printf("6 - Remover aluno da fila única; \n");
  printf("7 - Imprimir todas as filas; \n");
  printf("8 - Sair do programa; \n\n");
  scanf("%d", &opcao);

  return opcao;
}