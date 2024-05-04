#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pilha{
  int dados[50];
  int top;
}; typedef struct pilha Pilha;

struct pilhaChar{
  char palavra[40];
  int top;
}; typedef struct pilhaChar pilhaChar;

Pilha* inicializaPilha(void){
  Pilha *no;

  no = (Pilha*) malloc(sizeof(Pilha));
  if (no == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  no->top = 0;
  
  return no;
}

Pilha* pushPilha(Pilha *p, int insert){
  p->dados[p->top] = insert;
  p->top++;

  return p;
}

Pilha* popPilha(Pilha *p){
  if (p->top == 0){
    printf("\nNão há mais elementos na lista há serem retirados; \n\n");
  }
  else {
    p->dados[p->top-1] = 0;
    p->top--;
  }

  return p;
}

void imprimePilha(Pilha *p){

  int i;

  printf("\n");
  for (i = 0; i < p->top; i++){
    printf("[%d] ", p->dados[i]);
  }
  printf("\n\n");

}

Pilha* esvaziaPilha(Pilha *p){

  int i;

  for (i = 0; i < p->top; i++){
    p->dados[i] = 0;
    p->top--;
  }
  p->top--; // senão fica = 1

  return p;
}

pilhaChar* inicializaPilhaChar(void){
  pilhaChar *no;

  no = (pilhaChar*) malloc(sizeof(pilhaChar));
  if (no == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  no->top = 0;
  
  return no;
}

pilhaChar* pushPilhaChar(pilhaChar *p, char *insert){
  
  char test = '0';

  while (test != '\0'){
    p->palavra[p->top] = insert[p->top];
    p->top++;
    test = insert[p->top];
  }
  
  return p;
}

void imprimePilhaChar(pilhaChar *p){

  printf("\n");
  printf("%s", p->palavra);
  printf("\n\n");

}

bool pilhaIsPalindromo(pilhaChar *p){

  int esqDir, dirEsq;
  bool check = true;

  dirEsq = p->top-1;

  for (esqDir = 0; esqDir < p->top; esqDir++){
    if (p->palavra[esqDir] != p->palavra[dirEsq]){
      check = false;
    }
    dirEsq--;
  }

  return check;
}

Pilha* concatenaPilhas(Pilha *p1, Pilha *p2){

  int i;

  for (i = 0; i < p2->top; i++){
    p1 = pushPilha(p1, p2->dados[i]);
  }

  esvaziaPilha(p2);

  return p1;
}