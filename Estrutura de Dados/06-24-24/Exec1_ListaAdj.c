#include <stdio.h>
#include <stdlib.h>
#include "functions_ListaAdj.c"

int main(){

  ListaAdj *grafo[8];

  inicializaGrafoLista(grafo, 8);

  grafo[0] = insereElementoGrafoLista(grafo[0], 2);
  grafo[0]->prox = insereElementoGrafoLista(grafo[0]->prox, 3);
  grafo[0]->prox->prox = insereElementoGrafoLista(grafo[0]->prox->prox, 4);
  grafo[0]->prox->prox->prox = insereElementoGrafoLista(grafo[0]->prox->prox->prox, 5);
  
  grafo[1] = NULL;

  grafo[2] = insereElementoGrafoLista(grafo[2], 3);

  grafo[3] = insereElementoGrafoLista(grafo[3], 1);
  
  grafo[4] = insereElementoGrafoLista(grafo[4], 6);

  grafo[5] = insereElementoGrafoLista(grafo[5], 7);

  grafo[6] = NULL;

  grafo[7] = insereElementoGrafoLista(grafo[7], 0);

  imprimeGrafoLista(grafo, 7);


  system("pause");
  return 0;
}