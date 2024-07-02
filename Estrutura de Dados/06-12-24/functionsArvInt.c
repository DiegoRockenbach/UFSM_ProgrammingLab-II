#include <stdio.h>
#include <stdlib.h>

struct arvI {
  int info;
  struct arvI* esq;
  struct arvI* dir;
}; typedef struct arvI ArvoreInt;

int contaNumPares(ArvoreInt *raiz){

  int count = 0;

  if (raiz == NULL){
    return 0;
  }
  if (raiz->info%2 == 0){
    count = 1;
  }

  return count + contaNumPares(raiz->esq) + contaNumPares(raiz->dir);
}

void imprimePercursoPosOrdem(ArvoreInt *raiz){

  if (raiz != NULL){
    imprimePercursoPosOrdem(raiz->esq);
    imprimePercursoPosOrdem(raiz->dir);
    printf("%d ", raiz->info);
  }

}

ArvoreInt* inicializaArvoreInt(int insert, ArvoreInt *filhoEsq, ArvoreInt *filhoDir){

  ArvoreInt *p;

  p = (ArvoreInt*) malloc(sizeof(ArvoreInt));
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