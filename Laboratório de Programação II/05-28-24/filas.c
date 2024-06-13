#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filas.h"

FilaAlunos* insereAlunoFilasExternas(FilaAlunos *fila){

  int ticketInsert;
  FilaAlunos *p, *novo;

  novo = (FilaAlunos*) malloc(sizeof(FilaAlunos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;

  printf("\nInsira um número de 3 dígitos que será o ticket do aluno que está entrando na fila: \n");
  scanf("%d", &ticketInsert);
  if (ticketInsert < 100 || ticketInsert > 999){
    printf("\nTicket inválido inserido; \n");
    return fila;
  }
  novo->ticket = ticketInsert;

  p = fila;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }

  return fila;
}

FilaAlunos* insereAlunoFilaUnica(FilaAlunos *filaUnica, FilaAlunos *filaExt){

  FilaAlunos *p, *novo;

  novo = (FilaAlunos*) malloc(sizeof(FilaAlunos));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->prox = NULL;
  novo->ticket = filaExt->ticket;

  p = filaUnica;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }

  return filaUnica;
}

bool isFilaUnicaCheia(FilaAlunos *filaUnica){

  FilaAlunos *p;
  int quant = 0;

  p = filaUnica;
  if (p != NULL){
    while (p->prox != NULL){
      quant++;
      p = p->prox;
    }
  }
  else {
    return false;
  }

  if (quant > 10){
    return true;
  }
  else {
    return false;
  }
}

FilaAlunos* geraFilaUnica(FilaAlunos *filaUnica, FilaAlunos **filaExtNormal, FilaAlunos **filaExtPrioritaria){

  while (*filaExtPrioritaria != NULL){
    if (isFilaUnicaCheia(filaUnica) == false){
      filaUnica = insereAlunoFilaUnica(filaUnica, *filaExtPrioritaria);
      *filaExtPrioritaria = removeAlunoFila(*filaExtPrioritaria);
    }
    else {
      return filaUnica;
    }
  }

  while (*filaExtNormal != NULL){
    if (isFilaUnicaCheia(filaUnica) == false){
      filaUnica = insereAlunoFilaUnica(filaUnica, *filaExtNormal);
      *filaExtNormal = removeAlunoFila(*filaExtNormal);
    }
    else {
      return filaUnica;
    }
  }

  return filaUnica;
}

FilaAlunos* removeAlunoFila(FilaAlunos *fila){
  
  if (fila->prox != NULL){
    fila = fila->prox;
  }
  else {
    fila = NULL;
  }

  return fila;
}

void imprimeFila(FilaAlunos *fila){

  if (fila == NULL){
    printf("\nA fila está vazia; \n");
  }
  while (fila != NULL){
    printf("[%d]; ", fila->ticket);

    if (fila->prox != NULL){
      fila = fila->prox;
    }
    else {
      break;
    }
  }

}

void imprimeTodasFilas(FilaAlunos *filaUnica, FilaAlunos *filaExtNormal, FilaAlunos *filaExtPrioritaria){

  printf("\n\nFila única: \n\n");
  imprimeFila(filaUnica);
  printf("\n\nFila externa de prioridade normal: \n\n");
  imprimeFila(filaExtNormal);
  printf("\n\nFila externa de prioridade alta: \n\n");
  imprimeFila(filaExtPrioritaria);

}