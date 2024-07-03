#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arv {
  int data;
  struct arv* esq;
  struct arv* dir;
}; typedef struct arv Arvore;

Arvore* inverteFilhosABB(Arvore *raiz){

  Arvore *temp;

  if (raiz != NULL){
    if (raiz->esq != NULL){
      inverteFilhosABB(raiz->esq);
    }
    if (raiz->dir != NULL){
      inverteFilhosABB(raiz->dir);
    }
    if (raiz->esq != NULL && raiz->dir != NULL){

      temp = (Arvore*) malloc(sizeof(Arvore));
      if (temp == NULL){
        printf("\nErro de alocação de memória!\n\n");
        system("pause");
        return NULL;
      }
      temp = raiz->esq;
      raiz->esq = raiz->dir;
      raiz->dir = temp;
    }
  }

  return raiz;
}

bool isABB(Arvore *raiz){

  if (raiz != NULL){
    if (raiz->esq != NULL && raiz->dir != NULL){
      if (raiz->esq->data > raiz->dir->data){
        return false;
      }
    }
    if (raiz->esq != NULL){
      if (raiz->esq->data > raiz->data){
        return false;
      }
      return isABB(raiz->esq);
    }
    if (raiz->dir != NULL){
      if (raiz->dir->data < raiz->data){
        return false;
      }
      return isABB(raiz->dir);
    }

    return true;
  }

  return false;
}

void imprimeABBDecrescente(Arvore *raiz){
  
  if (raiz != NULL){
    imprimeABBDecrescente(raiz->dir);
    printf("%d; ",raiz->data);
    imprimeABBDecrescente(raiz->esq);
  }

}

void imprimeABBCrescente(Arvore *raiz){
  
  if (raiz != NULL){
    imprimeABBCrescente(raiz->esq);
    printf("%d; ",raiz->data);
    imprimeABBCrescente(raiz->dir);
  }

}

Arvore* insereNoABB(Arvore *raiz, int insert){

  Arvore *novo;

  novo = (Arvore*) malloc(sizeof(Arvore));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->esq = NULL;
  novo->dir = NULL;
  novo->data = insert;

  if (raiz == NULL){
    return novo;
  }
  if (novo->data < raiz->data){
    raiz->esq = insereNoABB(raiz->esq, novo->data);
  }
  else {
    raiz->dir = insereNoABB(raiz->dir, novo->data);
  }

  return raiz;
}