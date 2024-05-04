#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  char insert[40];
  pilhaChar *no;

  no = inicializaPilhaChar();
  printf("\nInsira uma palavra para verificar se ela é um palíndromo ou não: \n");
  gets(insert);
  no = pushPilhaChar(no, insert);

  

  printf("\nA palavra inserida foi a seguinte: \n");
  imprimePilhaChar(no);

  if (pilhaIsPalindromo(no)){
    printf("\nA palavra inserida é um palíndromo!\n\n");
  }
  else {
    printf("\nA palavra inserida NÃO é um palíndromo!\n\n");
  }

  system("pause");
  return 0;
}