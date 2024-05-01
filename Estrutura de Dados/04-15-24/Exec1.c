#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Lista2 *no, *pontPenultimo, *pontUltimo;

  no = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na lista:\n");
    scanf("%d", &insert);
    no = insereNoFinal(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  imprimeLista(no);
  pontUltimo = ultimoElemento(no);
  printf("\nO ultimo elemento da lista é %d, e o penúltimo elemento é %d;\n", pontUltimo->dados, pontUltimo->ant->dados);

  system ("pause");
  return 0;
}