#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct veiculo_t {
  int placa;
  char marca[50];
  char modelo[50];
  int anoFabr;
  int quilometragem;
  float valorDiaria;
  bool disponivel;
}; typedef struct veiculo_t Veiculo;

struct veiculos {
  Veiculo dados;
  struct veiculos *prox;
}; typedef struct veiculos Veiculos;

Veiculos* addVeiculo(Veiculos *inicio);

void listaVeiculos(Veiculos *inicio);