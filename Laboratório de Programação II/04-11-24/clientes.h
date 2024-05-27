#ifndef __CLIENTESH_INCLUDED__
#define __CLIENTESH_INCLUDED__
  
#include <stdio.h>
#include <stdlib.h>

struct cliente_t {
  char nome[50];
  char cnh[50];
  char telefone[50];
}; typedef struct cliente_t Cliente;

struct clientes {
  Cliente dados;
  struct clientes *prox;
}; typedef struct clientes Clientes;

void bufferClientes();

Clientes* addCliente(Clientes *inicio);

void listaClientes(Clientes *inicio);

Cliente* buscaCliente(Clientes *inicio, char *cnh);

#endif