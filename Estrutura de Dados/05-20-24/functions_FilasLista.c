#include <stdio.h>
#include <stdlib.h>

struct lista_t{
  int dados;
  struct lista_t *prox;
}; typedef struct lista_t Lista;

struct fila_t{
  Lista* inicio;
  Lista* fim;
}; typedef struct fila_t FilaLista;

FilaLista* inicializaFilaLista(FilaLista *fila){

  fila->inicio = (Lista*) malloc(sizeof(Lista));
  if (fila->inicio == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  fila->inicio->prox = NULL;

  fila->fim = (Lista*) malloc(sizeof(Lista));
  if (fila->fim == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  fila->fim->prox = NULL;

  return fila;
}

FilaLista* insereFilaLista(FilaLista *fila, int insert){

  Lista *novo, *p;

  novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->dados = insert;
  novo->prox = NULL;

  p = fila->inicio;
  if (p != NULL){
    fila->inicio = p;
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
    fila->fim = p->prox;
  }
  else {
    fila->inicio = novo;
    fila->fim = novo;
  }

  return fila;
}

FilaLista* popFilaLista(FilaLista *fila){

  if (fila->inicio != NULL){
    fila->inicio = fila->inicio->prox;
  }
  else {
    printf("\nA fila já está vazia, portanto, não foi possível retirar elementos");
  }
  
  return fila;
}

void imprimeFilaLista(FilaLista *fila){

  Lista* p;

  p = fila->inicio;
  while (p != NULL){
    printf("%d; ", p->dados);
    if (p->prox != NULL){
      p = p->prox;
    }
    else {
      break;
    }
  }
  if (p == NULL) {
    printf("A fila está vazia, portanto, não há nada a imprimir;");
  }

  printf("\n\n");

}

void combinaFilasLista(FilaLista *f_res, FilaLista *f1, FilaLista *f2){ // Exec2

  int count = 1;  // sempre flutua entre 1 e 2, que é o que define se o valor que vai pra f_res é de f1 ou f2

  while (f1->inicio != NULL || f2->inicio != NULL){
    if (count == 1 && f1->inicio != NULL){
      f_res = insereFilaLista(f_res, f1->inicio->dados);
      f1 = popFilaLista(f1);
      count++;
    }
    if (count == 2 && f2->inicio != NULL) {
      f_res = insereFilaLista(f_res, f2->inicio->dados);
      f2 = popFilaLista(f2);
      count--;
    }
    else {
      break;
    }
  }

}

FilaLista* ordenaFilasLista(FilaLista *f1, FilaLista *f2){

  FilaLista *f_res;

  f_res = (FilaLista*) malloc(sizeof(FilaLista));
  if (f_res == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return 0;
  }
  f_res = inicializaFilaLista(f_res);
  f_res->inicio = NULL;
  f_res->fim = NULL;

  while (f1->inicio != NULL || f2->inicio != NULL){
    if (f1->inicio == NULL && f2->inicio != NULL){
      f_res = insereFilaLista(f_res, f2->inicio->dados);
      f2 = popFilaLista(f2);
      continue;
      imprimeFilaLista(f_res);
    }
    else if (f1->inicio != NULL && f2->inicio == NULL){
      f_res = insereFilaLista(f_res, f1->inicio->dados);
      f1 = popFilaLista(f1);
      continue;
      imprimeFilaLista(f_res);
    }

    else if (f1->inicio->dados <= f2->inicio->dados){
      f_res = insereFilaLista(f_res, f1->inicio->dados);
      f1 = popFilaLista(f1);
    }
    else if (f1->inicio->dados > f2->inicio->dados) {
      f_res = insereFilaLista(f_res, f2->inicio->dados);
      f2 = popFilaLista(f2);
    }
  }

  return f_res;
}