#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arvC {
  char info;
  struct arvC* esq;
  struct arvC* dir;
}; typedef struct arvC ArvoreChar;

bool isArvoresEqual(ArvoreChar *raizA, ArvoreChar *raizB){

  bool flag = false;

  if (raizA == NULL && raizB == NULL){
    flag = true;
  }
  if (raizA == NULL && raizB != NULL){
    flag = false;
  }
  if (raizA != NULL && raizB == NULL){
    flag = false;
  }
  if (raizA != NULL && raizB != NULL){
    flag = isArvoresEqual(raizA->esq, raizB->esq);
    if (flag == true){
      flag = isArvoresEqual(raizA->dir, raizB->dir);
    }
  }

  return flag;
}

int contaNosUmFilho(ArvoreChar *raiz){

  int quant = 0;

  if (raiz == NULL){
    return 0;
  }
  if ((raiz->esq == NULL) ^ (raiz->dir == NULL)){ // ^ LOGICAL XOR
    quant = 1;
  }

  return quant + contaNosUmFilho(raiz->esq) + contaNosUmFilho(raiz->dir);
}

int contaLeafNodes(ArvoreChar *raiz){

  int quant = 0;

  if (raiz == NULL){
    return 0;
  }
  if (raiz->esq == NULL && raiz->dir == NULL){
    quant = 1;  
  }

  return quant + contaLeafNodes(raiz->esq) + contaLeafNodes(raiz->dir);
}

ArvoreChar* copiaArvoreChar(ArvoreChar *raizOrig){

  ArvoreChar *raizCopia;

  if (raizOrig != NULL){
    copiaArvoreChar(raizOrig->esq);
    copiaArvoreChar(raizOrig->dir);
    raizCopia = (ArvoreChar*) malloc(sizeof(ArvoreChar));
    if (raizCopia == NULL){
      printf("\nErro de alocação de memória!\n\n");
      system("pause");
      return NULL;
    }
    raizCopia->esq = raizOrig->esq;
    raizCopia->dir = raizOrig->dir;
    raizCopia->info = raizOrig->info;
  }
  
  return raizCopia;
}

void imprimePercursoOrdemSimetrica(ArvoreChar *raiz){

  if (raiz != NULL){
    imprimePercursoOrdemSimetrica(raiz->esq);
    printf("%c ", raiz->info);
    imprimePercursoOrdemSimetrica(raiz->dir);
  }

}

void imprimePercursoPosOrdem(ArvoreChar *raiz){

  if (raiz != NULL){
    imprimePercursoPosOrdem(raiz->esq);
    imprimePercursoPosOrdem(raiz->dir);
    printf("%c ", raiz->info);
  }

}

void imprimePercursoPreOrdem(ArvoreChar *raiz){

  if (raiz != NULL){
    printf("%c ", raiz->info);
    imprimePercursoPreOrdem(raiz->esq);
    imprimePercursoPreOrdem(raiz->dir);
  }

}

ArvoreChar* inicializaArvoreChar(char insert, ArvoreChar *filhoEsq, ArvoreChar *filhoDir){

  ArvoreChar *p;

  p = (ArvoreChar*) malloc(sizeof(ArvoreChar));
  if (p == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  p->esq = filhoEsq;
  p->dir = filhoDir;
  p->info = insert;

  return p;
}