#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "veiculos.h"
#include "locacoes.h"

void bufferLocacoes(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}

Locacoes* addLocacao(Clientes *inicioCli, Veiculos *inicioVeic, Locacoes *inicioLoca){

  Locacoes *p, *novo;
  char cnh[50], placa[50];

  novo = (Locacoes*) malloc(sizeof(Locacoes));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;

  
  printf("\nQual o CNH do cliente que deseja realizar a locação? (0 se deseja cancelar a locação) \n");
  bufferLocacoes();
  gets(cnh);

  while (strcmp(cnh, "0") != 0){
    if (buscaCliente(inicioCli, cnh) == NULL){
      printf("\nCNH do cliente não encontrada no banco de dados! Insira novamente por favor: \n");
      printf("\nQual o CNH do cliente que deseja realizar a locação? (0 se deseja cancelar a locação) \n");
      gets(cnh);
    }
    else {
      novo->dados.cliente = buscaCliente(inicioCli, cnh);
      break;
    }
  }
  if (strcmp(cnh, "0") == 0){
    return inicioLoca;
  }
  

  printf("\nQual a placa do veículo que será locado? (0 se deseja cancelar a locação) \n");
  gets(placa);

  while (strcmp(placa, "0") != 0){
    if (buscaVeiculo(inicioVeic, placa) == NULL){
      printf("\nPlaca do veículo não encontrado no banco de dados! Insira novamente por favor: \n");
      printf("\nQual a placa do veículo que será locado? (0 se deseja cancelar a locação) \n");
      gets(placa);
    }
    else {
      novo->dados.veiculo = buscaVeiculo(inicioVeic, placa);
      break;
    }
  }
  if (strcmp(placa, "0") == 0){
    return inicioLoca;
  }
  else if (novo->dados.veiculo->disponivel == false){
    printf("\nO veículo em questão não está disponível para locação. \n");
    return inicioLoca;
  }
  novo->dados.veiculo->disponivel = false;

  novo->dados.retirada.dia = retornaDiaAtual();
  novo->dados.retirada.mes = retornaMesAtual();
  novo->dados.retirada.ano = retornaAnoAtual();

  while (true){
    printf("\nEm qual data o veículo será devolvido? (formato DD MM AA) \n");
    scanf("%d %d %d", &novo->dados.devolucao.dia, &novo->dados.devolucao.mes, &novo->dados.devolucao.ano);
    
    if (novo->dados.devolucao.dia > 31 || novo->dados.devolucao.mes > 12){
      printf("\nData inválida inserida! Insira novamente: \n");
    }
    else if (difDiasEntreDatas(novo->dados.retirada, novo->dados.devolucao) < 0){
      printf("\nA data de devolução deve ser após a data de retirada! Insira novamente: \n");
    }
    else {
      break;
    }
  }
  novo->dados.valorPago = (difDiasEntreDatas(novo->dados.retirada, novo->dados.devolucao)) * (novo->dados.veiculo->valorDiaria);


  p = inicioLoca;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }

  return inicioLoca;
}

void listaLocacoes(Locacoes *inicio){

  int count = 0;

  if (inicio == NULL){
    printf("\nNenhuma locação registrada no banco de dados; \n");
  }
  while (inicio != NULL){
    count++;
    printf("\n%dª LOCAÇÃO: \n\n", count);
    printf("Placa do veículo locado - %s;\n", inicio->dados.veiculo->placa);
    printf("CNH do cliente que realizou a locação - %s;\n", inicio->dados.cliente->cnh);
    printf("Data que o carro foi retirado - %d %d %d;\n", inicio->dados.retirada.dia, inicio->dados.retirada.mes, inicio->dados.retirada.ano);
    printf("Data que o carro deve ser devolvido - %d %d %d;\n", inicio->dados.devolucao.dia, inicio->dados.devolucao.mes, inicio->dados.devolucao.ano);
    printf("Valor a ser pago - R$ %.2f;\n", inicio->dados.valorPago);
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      break;
    }
  }

}

Locacoes* deletaLocacao(Locacoes *inicio, Locacoes *p, Locacoes *pAnt){

  if (inicio == p){
    return p->prox;
  }
  else if (pAnt->prox == p && p->prox != NULL){
    pAnt->prox = p->prox;
  }
  else if (p->prox == NULL){
    pAnt->prox = NULL;
  }

  return inicio;
}

Locacoes* resolveLocacao(Locacoes *inicio){

  Locacoes *p, *pAnt = NULL;
  int km = 0;
  char placa[50];

  printf("\nQual a placa do veículo locado? \n");
  bufferLocacoes();
  gets(placa);

  p = inicio;
  if (p == NULL){
    printf("\nNenhuma locação registrada no banco de dados; \n");
  }
  while(p != NULL){
    if ((strcmp(p->dados.veiculo->placa, placa) == 0) && (p->dados.veiculo->disponivel == false)){
      printf("\nQuantos quilômetros foram rodados durante a locação? (arredondado) \n");
      scanf("%d", &km);
      p->dados.veiculo->quilometragem = p->dados.veiculo->quilometragem + km;
      p->dados.veiculo->disponivel = true;
      printf("\nValor a ser pago: %.2f;\n", p->dados.valorPago);
      inicio = deletaLocacao(inicio, p, pAnt);
      printf("\nVeículo devolvido!\n");
      break;
    }
    else if (p->prox == NULL){
      printf("Placa inserida não encontrada entre os veículos locados cadastrados; \n");
      break;
    }
    else {
      pAnt = p;
      p = p->prox;
    }
  }

  

  return inicio;
}