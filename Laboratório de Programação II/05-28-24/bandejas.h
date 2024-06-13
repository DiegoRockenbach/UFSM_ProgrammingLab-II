#ifndef __BANDEJASH_INCLUDED__
#define __BANDEJASH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

struct PilhaBandejas_t {
  int id;
  struct PilhaBandejas_t *prox;
};typedef struct PilhaBandejas_t PilhaBandejas;

PilhaBandejas* adicionaBandeja(PilhaBandejas *bandejas);

int geraIdBandeja(PilhaBandejas *bandejaFinal);

PilhaBandejas* percorrePilha(PilhaBandejas *bandejas);

PilhaBandejas* repoeBandejas(PilhaBandejas *bandejas);

PilhaBandejas* alunoRetiraBandeja(PilhaBandejas *bandejas);

void imprimeBandejas(PilhaBandejas *bandejas);

#endif