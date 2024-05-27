#ifndef __LOCACOESH_INCLUDED__
#define __LOCACOESH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "veiculos.h"
#include "dates.h"

struct locacao_t {
  Cliente *cliente;
  Veiculo *veiculo;
  Date retirada;
  Date devolucao;
  float valorPago;
}; typedef struct locacao_t Locacao;

struct locacoes {
  Locacao dados;
  struct locacoes *prox;
}; typedef struct locacoes Locacoes;

void bufferLocacoes();

Locacoes* addLocacao(Clientes *inicioCli, Veiculos *inicioVeic, Locacoes *inicioLoca);

Locacoes* deletaLocacao(Locacoes *inicio, Locacoes *p, Locacoes *pAnt);

Locacoes* resolveLocacao(Locacoes *inicio);

void listaLocacoes(Locacoes *inicio);
  
#endif