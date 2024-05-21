#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "veiculos.h"

Veiculos* addVeiculo(Veiculos *inicio){

/*   Veiculos *p, *novo;

  novo = (Veiculos*) malloc(sizeof(Veiculos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;

  printf("\nInsira as informações do veículo a ser inserido: \n\n");
  printf("PLACA:\n");
  scanf("%d", &novo->dados.placa);
  printf("MARCA:\n");
  gets(novo->dados.marca);
  printf("MODELO:\n");
  gets(novo->dados.modelo);
  printf("ANO DE FABRICAÇÃO:\n");
  scanf("%d", &novo->dados.anoFabr);
  printf("QUILOMETRAGEM ATUAL:\n");
  scanf("%d", &novo->dados.quilometragem);
  printf("VALOR DA DIÁRIA:\n");
  scanf("%f", &novo->dados.valorDiaria);
  novo->dados.disponivel = true;

  p = inicio;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  } */

  return inicio;
}

void listaVeiculos(Veiculos *inicio){

  int count = 0;

  while (inicio != NULL){
    count++;
    printf("\n%d° CARRO: \n\n", count);
    printf("Placa - %d;\n", inicio->dados.placa);
    printf("Marca - %s;\n", inicio->dados.marca);
    printf("Modelo - %s;\n", inicio->dados.modelo);
    printf("Ano de fabricação - %d;\n", inicio->dados.anoFabr);
    printf("Quilometragem anual - %d;\n", inicio->dados.quilometragem);
    printf("Valor da diária - R$ %.2f;\n", inicio->dados.valorDiaria);
    if (inicio->dados.disponivel == true){
      printf("O carro está disponível;\n");
    }
    else {
      printf("O carro NÃO está disponível!\n");
    }
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      break;
    }
  }
}