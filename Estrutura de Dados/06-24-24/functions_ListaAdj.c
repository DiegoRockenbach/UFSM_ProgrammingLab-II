#include <stdio.h>
#include <stdlib.h>

struct listaAdj {
  int apontado;
  struct listaAdj *prox;
}; typedef struct listaAdj ListaAdj;

void imprimeGrafoLista(ListaAdj **grafo, int tam){

  int i;
  ListaAdj *p;

  for (i = 0; i < tam; i++){
    if (grafo[i] != NULL){
      printf("\n\nO número %d aponta para: ", i);
      for (p = grafo[i]; p != NULL; p = p->prox){
        printf("[%d]; ", p->apontado);
        if (p->prox == NULL){
          continue;
        }
      }
    }
    else {
      printf("\n\nO número %d não aponta para ninguém;", i);
    }
  }

  printf("\n\n");

}

ListaAdj* insereElementoGrafoLista(ListaAdj *grafo, int insert){

  grafo = (ListaAdj*) malloc(sizeof(ListaAdj));
  if (grafo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  grafo->prox = NULL;
  grafo->apontado = insert;

  return grafo;
}

void inicializaGrafoLista(ListaAdj **grafo, int tam){
  
  int i;

  for (i = 0; i < tam; i++){
    grafo[i] = NULL;
  }
}