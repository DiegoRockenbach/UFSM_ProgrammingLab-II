#ifndef __RELATORIOSH_INCLUDED__
#define __RELATORIOSH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "locacoes.h"
#include "veiculos.h"

void bufferRelatorios();

void imprimeLocacoesDataX(Locacoes *inicio);

void imprimeLocacoesClienteX(Locacoes *inicio);

void imprimeFaturamentoLocacoesMensal(Locacoes *inicio);

void imprimeTop3Quilometragem(Veiculos *inicio);

void imprimeVeiculosNaoLocados(Veiculos *inicio);

#endif