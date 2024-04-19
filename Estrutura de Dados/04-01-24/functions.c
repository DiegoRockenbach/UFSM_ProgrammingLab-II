#include <stdio.h>
#include <stdlib.h>

struct lista {
  int dados;
  struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializaLista(void){
  return NULL;
}

Lista* insereNoFinal(Lista *l, int i){
  
  Lista *novo, *p;
  
  novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->dados = i;
  novo->prox = NULL;

  p = l;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }
  
  return l;
}

void imprimeLista(Lista *l){

  Lista *p;

  printf("\n\n");
  for (p = l; p != NULL; p = p->prox){
    printf("[%d] ", p->dados);
  }
  printf("\n\n");

}

Lista* inverteSinal(Lista *l){

  Lista *p;

  p = l;
  while (p != NULL){
    p->dados = p->dados * (-1);
    p = p->prox;
  }

  return l;
}

float calculaMediaLista(Lista *l){

  int count = 0;
  float media = 0;
  Lista *p;

  p = l;
  while (p != NULL){
    count++;
    media = media + p->dados;
    p = p->prox;
  }
  media = media/count;

  return media;
}

Lista* insereNoOrdenado(Lista *l, int i){
    
  Lista *novo, *p, *pAnt, *pSeg;
  
  novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->dados = i;
  novo->prox = NULL;

  p = l;
  while (p != NULL){
    if (p->prox != NULL){
      pSeg = p->prox;
    }
    if ((i >= p->dados && p->prox == NULL) || (i >= p->dados && i <= pSeg->dados)){
      pAnt = p->prox;
      p->prox = novo;
      novo->prox = pAnt;
      return l;
    }
    else if (i <= p->dados){
      novo->prox = p;
      return novo;
    }
    else {
      p = p->prox;
    }
  }
  
  return novo;
}



Lista* retiraNoAntLista(Lista *l, int v){

  Lista *p, *temp, *pAnt, *pSeg;

  p = l;
  while (p != NULL){
    if (p->prox != NULL){
      pSeg = p->prox;
    }
    if (v <= pSeg->dados && v >= p->dados){
      temp = p->prox;
      pAnt->prox = temp;
      return l;
    }
    else {
      pAnt = p;
      p = p->prox;
    }
  }
  
  return l;
}