#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int stop = 0, insert, n, quant;
  Lista *no;

  no = inicializaLista();

  while (stop != 1){
    printf("\nInsira um valor que deseja inserir na lista:\n");
    scanf("%d", &insert);
    no = insereNo(no, insert);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  printf("\nInsira um valor inteiro 'n', para ser retornado o números de nós na lista com valores maiores que o valor 'n' inserido: \n");
  scanf("%d", &n);
  quant = contaDadosMaiorQue(no, n);

  printf("\nA quantidade de nós na lista com valores maiores que %d é de %d elementos; \n", n, quant);
  imprimeLista(no);

  system("pause");
  return 0;
}