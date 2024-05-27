#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientes.h"

void bufferClientes(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}

Clientes* addCliente(Clientes *inicio){
  
  Clientes *p, *novo;

  novo = (Clientes*) malloc(sizeof(Clientes));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;

  printf("\nInsira as informações do cliente a ser inserido: \n\n");
  printf("Nome:\n");
  bufferClientes();
  gets(novo->dados.nome);
  printf("Carteira Nacional de Habilitação (CNH):\n");
  gets(novo->dados.cnh);
  printf("Telefone para contato (sem espaços):\n");
  gets(novo->dados.telefone);

  p = inicio;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }

  return inicio;
}

void listaClientes(Clientes *inicio){

  int count = 0;

  if (inicio == NULL){
    printf("\nNenhum cliente registrado no banco de dados; \n");
  }
  while (inicio != NULL){
    count++;
    printf("\n%d° CLIENTE: \n\n", count);
    printf("Nome - ");
    puts(inicio->dados.nome);
    printf("CNH - ");
    puts(inicio->dados.cnh);
    printf("Telefone - ");
    puts(inicio->dados.telefone);
    if (inicio->prox != NULL){
      inicio = inicio->prox;
    }
    else {
      break;
    }
  }
}

Cliente* buscaCliente(Clientes *inicio, char *cnh){
  
  Cliente *found;

  if (inicio != NULL){
    while (true){
      if (strcmp(cnh, inicio->dados.cnh) == 0){
        found = &inicio->dados;
        return found;
      }
      if (inicio->prox != NULL){
        inicio = inicio->prox;
      }
      else {
        break;
      }
    }
  }

  return NULL;
}