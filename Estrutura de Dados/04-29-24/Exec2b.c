#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  Pilha *no;

  no = inicializaPilha();

  pushPilha(no, 3);
  popPilha(no);
  popPilha(no);
  pushPilha(no, 4);
  
  imprimePilha(no);
  popPilha(no);

  pushPilha(no, 1);
  popPilha(no);
  pushPilha(no, 2);
  pushPilha(no, 3);
  pushPilha(no, 4);
  pushPilha(no, 5);
  pushPilha(no, 6);
  pushPilha(no, 7);
  pushPilha(no, 8);

  imprimePilha(no);

  system("pause");
  return 0;
}