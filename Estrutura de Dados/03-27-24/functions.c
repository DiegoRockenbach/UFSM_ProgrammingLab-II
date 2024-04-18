#include <stdio.h>
#include <stdlib.h>

struct lista {
  int dados;
  struct lista *prox;
};
typedef struct lista Lista;

Lista* inicializaLista(void){
  return NULL;
}

Lista* insereNo(Lista *l, int i){
  
  Lista *novo;
  
  novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->dados = i;
  novo->prox = l;

  return novo;
}

void imprimeLista(Lista *l){

  Lista *p;

  printf("\n\n");
  for (p = l; p != NULL; p = p->prox){
    printf("[%d] ", p->dados);
  }
  printf("\n\n");

}

int comprimento(Lista *l){

  int count = 0;
  Lista *p;

  for (p = l; p != NULL; p = p->prox){
    count++;
  }

  return count;
}

int contaDadosMaiorQue(Lista *l, int n){

  int count = 0;
  Lista *p;

  for (p = l; p != NULL; p = p->prox){
    if (p->dados > n){
      count++;
    }
  }

  return count;
}

Lista* ultimo(Lista* l){

  Lista *p;

  for (p = l; p != NULL; p = p->prox){
    if (p->prox == NULL){
      return p;
    }
  }

  return p;
}

Lista* concatena(Lista* l1, Lista* l2){

  Lista *p, *q;

  for (p = l1; p != NULL; p = p->prox){
    if (p->prox == NULL){
      for (q = l2; q != NULL; q = q->prox){
        p->prox = q;
        p = p->prox;
      }
      p->prox = NULL;
    }
  }

  return l1;
}