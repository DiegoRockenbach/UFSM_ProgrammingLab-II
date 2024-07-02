#include <stdio.h>
#include <stdlib.h>
#include "functionsArvInt.c"

int main(){

  ArvoreInt *arv1, *arv2, *arv3, *arv4, *arv5, *arv6, *arv7, *arv8, *arv9, *arv10;

  arv9 = inicializaArvoreInt(9, NULL, NULL);
  arv7 = inicializaArvoreInt(7, arv9, NULL);
  arv5 = inicializaArvoreInt(5, arv7, NULL);

  arv10 = inicializaArvoreInt(10, NULL, NULL);
  arv8 = inicializaArvoreInt(8, arv10, NULL);
  arv6 = inicializaArvoreInt(6, NULL, arv8);

  arv4 = inicializaArvoreInt(4, arv5, arv6);
  arv3 = inicializaArvoreInt(3, arv4, NULL);
  arv2 = inicializaArvoreInt(2, NULL, arv3);
  arv1 = inicializaArvoreInt(1, NULL, arv2);

  printf("\nConsidere a seguinte árvore descrita em pré-ordem(mesma do exercício 1): \n");
  imprimePercursoPosOrdem(arv1);
  printf("\nNesta árvore, há %d números pares; \n\n", contaNumPares(arv1));

  system("pause");
  return 0;
}