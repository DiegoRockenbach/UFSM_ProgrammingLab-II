#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  Pilha *no;

  no = inicializaPilha();

  pushPilha(no, 4);
  imprimePilha(no);

  pushPilha(no, 3);
  imprimePilha(no);

  popPilha(no);
  imprimePilha(no);

  pushPilha(no, 8); //não sei o que quis dizer com PUSH(S, 8)
  imprimePilha(no);

  popPilha(no);
  imprimePilha(no);

  system("pause");
  return 0;
}