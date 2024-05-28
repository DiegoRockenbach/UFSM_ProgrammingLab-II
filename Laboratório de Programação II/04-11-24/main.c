#include <stdio.h>
#include <stdlib.h>
#include "menu.c"
#include "veiculos.h"
#include "clientes.h"
#include "locacoes.h"
#include "relatorios.h"

int main(){

  int opcaoMenu;
  Veiculos *veiculo;
  Clientes *cliente;
  Locacoes *locacao;

  veiculo = (Veiculos*) malloc(sizeof(Veiculos));
  if (veiculo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  veiculo = NULL;

  cliente = (Clientes*) malloc(sizeof(Clientes));
  if (cliente == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  cliente = NULL;

  locacao = (Locacoes*) malloc(sizeof(Locacoes));
  if (locacao == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  locacao = NULL;


  printf("\nBem vindo ao sistema de controle e locação de veículos a clientes!");
  
  while (true){
    opcaoMenu = imprimeMenu();
    if (opcaoMenu == 1){
      veiculo = addVeiculo(veiculo);
    }
    else if (opcaoMenu == 2){
      listaVeiculos(veiculo);
    }
    else if (opcaoMenu == 3){
      cliente = addCliente(cliente);
    }
    else if (opcaoMenu == 4){
      listaClientes(cliente);
    }
    else if (opcaoMenu == 5){
      locacao = addLocacao(cliente, veiculo, locacao);
    }
    else if (opcaoMenu == 6){
      locacao = resolveLocacao(locacao);
    }
    else if (opcaoMenu == 7){
      listaLocacoes(locacao);
    }
    else if (opcaoMenu == 8){
      printf("\nImpressão dos relatórios: \n\n");
      imprimeLocacoesDataX(locacao); // R1
      imprimeLocacoesClienteX(locacao); // R2
      imprimeFaturamentoLocacoesMensal(locacao); // R3
      imprimeTop3Quilometragem(veiculo); // R4
      imprimeVeiculosNaoLocados(veiculo); // R5
    }
    else if (opcaoMenu == 9){
      return 0;
    }
    else {
      printf("\nA opção escolhida foi inválida! \n");
    }
  }

  system("pause");
  return 0;
}