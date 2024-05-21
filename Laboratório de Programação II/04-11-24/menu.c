#include <stdio.h>
#include <stdlib.h>

int imprimeMenu(){

  int opcao;

  printf("\nEscolha uma das seguintes opções: \n\n");
  printf("1 - Incluir veículos;\n");
  printf("2 - Listar veículos;\n");
  printf("3 - Inclur clientes;\n");
  printf("4 - Listar clientes;\n");
  printf("5 - Realizar locação;\n");
  printf("6 - Devolver veículo;\n");
  printf("7 - Listar locações;\n");
  printf("8 - Relatórios;\n");
  printf("9 - Sair do programa;\n\n");
  scanf("%d", &opcao);

  return opcao;
}