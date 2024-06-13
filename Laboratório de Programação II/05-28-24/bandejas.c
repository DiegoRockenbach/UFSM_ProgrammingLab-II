#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "bandejas.h"

PilhaBandejas* adicionaBandeja(PilhaBandejas *bandejas){

  PilhaBandejas *p, *novo;

  novo = (PilhaBandejas*) malloc(sizeof(PilhaBandejas));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;

  p = bandejas;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }

  return bandejas;
}

int geraIdBandeja(PilhaBandejas *bandejaFinal){

  int id;
  PilhaBandejas *p;

  srand(time(NULL));

  id = rand() % 99;
  
  p = bandejaFinal;
  if (p == NULL){
    printf("\nA pilha de bandejas está vazia, portanto não foi possível gerar o iD; ");
    return 0;
  }
  while (p != NULL){
    if (id == p->id){
      id = rand() % 99;
      p = bandejaFinal;
      continue;
    }
    else if (p->prox != NULL){
      p = p->prox;
    }
    else if (p->prox == NULL){
      break;
    }
  }

  return id;
}

PilhaBandejas* percorrePilha(PilhaBandejas *bandejas){

  while (bandejas->prox != NULL){
    bandejas = bandejas->prox;
  }

  return bandejas;
}

PilhaBandejas* repoeBandejas(PilhaBandejas *bandejas){

  int i, quant;
  PilhaBandejas *finalPilha;

  printf("\nQuantas bandejas deseja adicionar à pilha? \n");
  scanf("%d", &quant);

  for (i = 0; i < quant; i++){
    bandejas = adicionaBandeja(bandejas);
    finalPilha = percorrePilha(bandejas);
    finalPilha->id = geraIdBandeja(bandejas);
  }

  return bandejas;
}

PilhaBandejas* alunoRetiraBandeja(PilhaBandejas *bandejas){

  PilhaBandejas *p, *finalPilha;

  finalPilha = percorrePilha(bandejas);
  p = bandejas;
  while (p != NULL){
    if (p->prox == finalPilha){
      p->prox = NULL;
      return bandejas;
    }
    else if (p->prox != NULL && p->prox != finalPilha){
      p = p->prox;
    }
  }

  return bandejas;
}

void imprimeBandejas(PilhaBandejas *bandejas){

  if (bandejas == NULL){
    printf("\nA pilha está vazia; \n");
  }
  while (bandejas != NULL){
    printf("[%02d]; ", bandejas->id);

    if (bandejas->prox != NULL){
      bandejas = bandejas->prox;
    }
    else {
      break;
    }
  }

}