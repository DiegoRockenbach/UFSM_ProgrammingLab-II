#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert;
  Lista *no, *ponteiroUltimo;

  no = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na lista:\n");
    scanf("%d", &insert);
    no = insereNo(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  ponteiroUltimo = ultimo(no);
  printf("\nO ponteiro para o último nó da lista encadeada inserida é %d;\n", ponteiroUltimo->dados);
  imprimeLista(no);

  system("pause");
  return 0;
}