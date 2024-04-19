#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert, val;
  Lista *no;

  no = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na lista:\n");
    scanf("%d", &insert);
    no = insereNoOrdenado(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  printf("\nAgora, insira um valor inteiro, de modo que o dado da lista diretamente anterior ao valor inserido será removido: \n");
  scanf("%d", &val);
  printf("\nA lista antes de ter o valor removido estava assim: ");
  imprimeLista(no);

  no = retiraNoAntLista(no, val);

  printf("\nE, após ter o valor removido, ficou assim: ");
  imprimeLista(no);

  system("pause");
  return 0;
}