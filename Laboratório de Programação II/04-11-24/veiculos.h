#ifndef __VEICULOSH_INCLUDED__
#define __VEICULOSH_INCLUDED__
  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct veiculo_t {
  char placa[50];
  char marca[50];
  char modelo[50];
  int anoFabr;
  long int quilometragem;
  float valorDiaria;
  bool disponivel;
}; typedef struct veiculo_t Veiculo;

struct veiculos {
  Veiculo dados;
  struct veiculos *prox;
}; typedef struct veiculos Veiculos;

void bufferVeiculos();

Veiculos* addVeiculo(Veiculos *inicio);

void listaVeiculos(Veiculos *inicio);

Veiculo* buscaVeiculo(Veiculos *inicio, char *placa);

#endif