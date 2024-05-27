#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "dates.h"
#include "locacoes.h"

void bufferRelatorios(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}

void imprimeLocacoesDataX(Locacoes *inicio){

  Date dataInserida;
  int count = 0, flag = 0;

  printf("\nRELATÓRIO R1: \n\n");
  printf("Insira uma data para checar as locações ativas nessa data (formato DD MM AA):");
  scanf("%d %d %d", &dataInserida.dia, &dataInserida.mes, &dataInserida.ano);

  if (inicio == NULL){
    printf("\nNenhuma locação registrada no banco de dados; \n");
  }
  while (inicio != NULL){
    if (difDiasEntreDatas(dataInserida, inicio->dados.devolucao) > 0){
      flag = 1;
      count++;
      printf("\n%dª LOCAÇÃO ATIVA NA DATA INSERIDA: \n\n", count);
      printf("Placa do veículo locado - %s;\n", inicio->dados.veiculo->placa);
      printf("CNH do cliente que realizou a locação - %s;\n", inicio->dados.cliente->cnh);
      printf("Data que o carro foi retirado - %d %d %d;\n", inicio->dados.retirada.dia, inicio->dados.retirada.mes, inicio->dados.retirada.ano);
      printf("Data que o carro deve ser devolvido - %d %d %d;\n", inicio->dados.devolucao.dia, inicio->dados.devolucao.mes, inicio->dados.devolucao.ano);
      printf("Valor a ser pago - R$ %.2f;\n", inicio->dados.valorPago);
    }
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      if (flag == 0){
        printf("\nNenhuma das locações atuais estarão ativas na data inserida; \n");
      }
      break;
    }
  }

}

void imprimeLocacoesClienteX(Locacoes *inicio){

  char cnhInserida[50];
  int count = 0, flag = 0;

  printf("\nRELATÓRIO R2: \n\n");
  printf("Insira a CNH de um cliente cadastrado para checar todas suas locações ativas: \n");
  bufferRelatorios();
  gets(cnhInserida);

  if (inicio == NULL){
    printf("\nNenhuma locação registrada no banco de dados; \n");
  }  
  while (inicio != NULL){
    if (strcmp(cnhInserida, inicio->dados.cliente->cnh) == 0){
      flag = 1;
      count++;
      printf("\n%dª LOCAÇÃO ATIVA DO CLIENTE DE CNH %s: \n\n", count, inicio->dados.cliente->cnh);
      printf("Placa do veículo locado - %s;\n", inicio->dados.veiculo->placa);
      printf("Nome do cliente que realizou a locação - %s;\n", inicio->dados.cliente->nome);
      printf("Data que o carro foi retirado - %d %d %d;\n", inicio->dados.retirada.dia, inicio->dados.retirada.mes, inicio->dados.retirada.ano);
      printf("Data que o carro deve ser devolvido - %d %d %d;\n", inicio->dados.devolucao.dia, inicio->dados.devolucao.mes, inicio->dados.devolucao.ano);
      printf("Valor a ser pago - R$ %.2f;\n", inicio->dados.valorPago);
    }
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      if (flag == 0){
        printf("\nNenhuma locação ativa atrelada à CNH inserida; \n");
      }
      break;
    }
  }

}

void imprimeFaturamentoLocacoesMensal(Locacoes *inicio){
  
  float faturamentoMensal = 0;

  printf("\nRELATÓRIO R3: \n\n");
  while (inicio != NULL){
    faturamentoMensal = faturamentoMensal + inicio->dados.valorPago;
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      break;
    }
  }
  
  if (inicio == NULL){
    printf("Nenhuma locação registrada no banco de dados; \n");
  }
  else {
    printf("Mensalmente, fatorando todas as locações ativas no presente momento, a locadora possui uma renda de R$ %.2f; \n", faturamentoMensal);
  }

}

void imprimeTop3Quilometragem(Veiculos *inicio){

  int prim = 0, seg = 0, terc = 0;
  char placaPrim[50], placaSeg[50], placaTerc[50];

  printf("\nRELATÓRIO R4: \n\n");
  while (inicio != NULL){
    if (inicio->dados.quilometragem > prim && inicio->dados.quilometragem >= seg){
      terc = seg;
      strcpy(placaTerc, placaSeg);
      seg = prim;
      strcpy(placaSeg, placaPrim);
      prim = inicio->dados.quilometragem;
      strcpy(placaPrim, inicio->dados.placa);
    }
    else if (inicio->dados.quilometragem > seg && inicio->dados.quilometragem >= terc){
      terc = seg;
      strcpy(placaTerc, placaSeg);
      seg = inicio->dados.quilometragem;
      strcpy(placaSeg, inicio->dados.placa);
    }
    else if (inicio->dados.quilometragem > terc){
      terc = inicio->dados.quilometragem;
      strcpy(placaTerc, inicio->dados.placa);
    }
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      break;
    }
  }

  if (inicio == NULL){
    printf("Nenhum veículo registrado no banco de dados; \n");
  }
  else {
    if (prim != 0 && seg != 0 && terc != 0){
      printf("A terceira maior quilometragem de todos os veículos locados é de %d km, do veículo de placa %s; \n", terc, placaTerc);
      printf("\nA segunda maior quilometragem de todos os veículos locados é de %d km, do veículo de placa %s; \n", seg, placaSeg);
      printf("\nA maior quilometragem de todos os veículos locados é de %d km, do veículo de placa %s; \n", prim, placaPrim);
    }
    else {
      printf("Não há veículos suficientes registrados para calcular o TOP3; \n");
    }
  }

}

void imprimeVeiculosNaoLocados(Veiculos *inicio){

  int count = 0, flag = 0;

  printf("\nRELATÓRIO R5: \n");
  if (inicio == NULL){
    printf("\nNenhum veículo registrado no banco de dados; \n");
  }
  while (inicio != NULL){
    if (inicio->dados.disponivel == true){
      flag = 1;
      count++;
      printf("\n%d° veículo disponível para locação: \n\n", count);
      printf("Placa - %s;\n", inicio->dados.placa);
      printf("Modelo - %s;\n", inicio->dados.modelo);
    }
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      if (flag == 0){
        printf("\nNenhum dos veículos registrados está disponível para locação; \n");
      }
      break;
    }
  }

}