#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

struct lista {
  int matricula;
  char *nome;
  struct lista* prox;
}; typedef struct lista Lista; 

char* alocaVetorNome(){

  char *vet;

  vet = (char*) malloc(50*sizeof(char));
  if (vet==NULL){
    printf("Memória insuficiente.\n");
    return NULL;
  }

  return vet;

}

void buffer(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}

Lista* insereNoFinal(Lista *l, int matricula, char *nome){
  
  Lista *novo, *p;
  
  novo = (Lista*) malloc(sizeof(Lista));
  novo->nome = alocaVetorNome();
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->matricula = matricula;
  strcpy(novo->nome, nome);
  novo->prox = NULL;

  p = l;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
  else {
    return novo;
  }
  
  return l;
}

void imprimeLista(Lista *l){

  Lista *p;

  printf("\n\n");
  for (p = l; p != NULL; p = p->prox){
    printf("[%d] - %s\n", p->matricula, p->nome);
  }
  printf("\n\n");

}

Lista* inicializaLista(void){
  return NULL;
}

int main(){

  int stop = 0, matricula;
  char *nome;
  Lista *no;

  no = inicializaLista();
  nome = alocaVetorNome();

  while (stop != 1){
    buffer();
    printf("\nInsira o nome do aluno que deseja inserir na lista: \n");
    gets(nome);
    printf("\nInsira a matrícula que deseja inserir na lista: \n");
    scanf("%d", &matricula);
    no = insereNoFinal(no, matricula, nome);
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }

  imprimeLista(no);

  system("pause");
  return 0;
}