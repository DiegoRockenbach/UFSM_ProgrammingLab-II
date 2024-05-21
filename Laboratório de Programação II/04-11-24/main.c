#include <stdio.h>
#include <stdlib.h>
#include "menu.c"
#include "veiculos.h"
/* #include "clientes.h"
#include "locacoes.h" */

/* struct clientes {
  Cliente dados;
  struct veiculos *prox;
}; typedef struct clientes Clientes;

struct locacoes {
  Locacao dados;
  struct locacoes *prox;
}; typedef struct locacoes Locacoes; */

int main(){

  int opcaoMenu;
  Veiculos *veiculo;
  /* Clientes *cliente;
  Locacoes *locacao; */

  veiculo = (Veiculos*) malloc(sizeof(Veiculos));
  if (veiculo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }

/*   cliente = (Clientes*) malloc(sizeof(Clientes));
  if (cliente == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  locacao = (Locacoes*) malloc(sizeof(Locacoes));
  if (locacao == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  } */


  printf("\nBem vindo ao sistema de controle e locação de veículos a clientes! \n");
  opcaoMenu = imprimeMenu();
  
  veiculo = addVeiculo(veiculo);

/*   if (opcaoMenu == 1){
    veiculo = addVeiculo(veiculo);
  }
  else if (opcaoMenu == 2){
    listaVeiculos(veiculo);
  }
  else if (opcaoMenu == 3){
    
  }
  else if (opcaoMenu == 4){
    
  }
  else if (opcaoMenu == 5){
    
  }
  else if (opcaoMenu == 6){
    
  }
  else if (opcaoMenu == 7){
    
  }
  else if (opcaoMenu == 8){
    
  }
  else if (opcaoMenu == 9){
    
  }
  else {
    printf("\nA opção escolhida foi inválida! \n");
    opcaoMenu = imprimeMenu();
  } */

  system("pause");
  return 0;
}