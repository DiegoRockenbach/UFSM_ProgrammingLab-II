#include <stdio.h>
#include <stdlib.h>

struct lista2{
  int dados;
  struct lista2* ant;
  struct lista2* prox;
}; typedef struct lista2 Lista2;

Lista2* inicializaLista(void){
  return NULL;
}

Lista2* insereNoFinal(Lista2 *l, int i){
  
  Lista2 *novo, *p;
  
  novo = (Lista2*) malloc(sizeof(Lista2));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->dados = i;
  novo->ant = NULL;
  novo->prox = NULL;

  p = l;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    novo->ant = p;
    p->prox = novo;
  }
  else {
    return novo;
  }
  
  return l;
}

void imprimeLista(Lista2 *l){

  Lista2 *p;

  printf("\n\n");
  for (p = l; p != NULL; p = p->prox){
    printf("[%d] ", p->dados);
  }
  printf("\n\n");

}

Lista2* ultimoElemento(Lista2* l){

  Lista2 *p;

  for (p = l; p != NULL; p = p->prox){
    if (p->prox == NULL){
      return p;
    }
  }

  return p;
}

Lista2* retiraNoAntLista(Lista2 *l, int v){

  Lista2 *p;

  p = l;
  while (p != NULL){
    if (p->prox != NULL){
      p = p->prox;
    }
    if (v <= p->prox->dados && v >= p->ant->dados){
      p->ant->prox = p->prox;
      p->prox->ant = p->ant;
      return l;
    }
  }
  
  return l;
}