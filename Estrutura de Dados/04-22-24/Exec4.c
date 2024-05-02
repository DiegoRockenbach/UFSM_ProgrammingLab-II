#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor {
  int codigo;
  char *nome;
  float salario;
}; typedef struct professor Professor;

struct aluno {
  int matricula;
  char *nome;
}; typedef struct aluno Aluno;

struct listaHet {
  int tipo;
  void *dados;
  struct listaHet *prox;
}; typedef struct listaHet ListaHet;

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

ListaHet* insereAlunoFinal(ListaHet *l, char *nome, int matricula){
  
  ListaHet *lst, *p;
  Aluno *novo;
  
  novo = (Aluno*) malloc(sizeof(Aluno));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }

  lst = (ListaHet*) malloc(sizeof(ListaHet));
  lst->tipo = 2;
  lst->dados = novo;
  lst->prox = NULL;
  
  novo->nome = alocaVetorNome();
  if (novo->nome == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  
  novo->matricula = matricula;
  strcpy(novo->nome, nome);

  p = l;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = lst;
  }
  else {
    return lst;
  }
  
  return l;
}

ListaHet* insereProfessorFinal(ListaHet *l, char *nome, int codigo, float salario){
  
  ListaHet *lst, *p;
  Professor *novo;
  
  novo = (Professor*) malloc(sizeof(Professor));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }

  lst = (ListaHet*) malloc(sizeof(ListaHet));
  lst->tipo = 1;
  lst->dados = novo;
  lst->prox = NULL;
  
  novo->nome = alocaVetorNome();
  if (novo->nome == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  
  novo->codigo = codigo;
  novo->salario = salario;
  strcpy(novo->nome, nome);

  p = l;
  if (p != NULL){
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = lst;
  }
  else {
    return lst;
  }
  
  return l;
}

ListaHet* inicializaLista(void){
  return NULL;
}

void imprimeLista(ListaHet *l){

  ListaHet *p;
  Professor *prof;
  Aluno *alu;

  printf("\n\n");
  for (p = l; p != NULL; p = p->prox){
    if (p->tipo == 1){
      prof = (Professor*)p->dados;
      printf("\nProfessor %s - {cod. %d} (R$ %.2f);\n", prof->nome, prof->codigo, prof->salario);
    }
    else {
      alu = (Aluno*)p->dados;
      printf("\nAluno %s - [%d];\n", alu->nome, alu->matricula);
    }
  }
  printf("\n\n");

}

int main(){

  int stop = 0, opcao, codigo, matricula;
  char *nome;
  float salario;
  ListaHet *no;

  no = inicializaLista();
  nome = alocaVetorNome();

  while (stop != 1){
    printf("\nVocê deseja inserir na lista um professor (digite '1') ou um aluno (digite '2')? \n");
    scanf("%d", &opcao);
    if (opcao == 1){
      buffer();
      printf("\nInsira o nome do professor que deseja inserir na lista: \n");
      gets(nome);
      printf("\nInsira o código deste professor: \n");
      scanf("%d", &codigo);
      printf("\nPor final, insira o salário deste professor: \n");
      scanf("%f", &salario);
      no = insereProfessorFinal(no, nome, codigo, salario);
    }
    else if (opcao == 2){
      buffer();
      printf("\nInsira o nome do aluno que deseja inserir na lista: \n");
      gets(nome);
      printf("\nInsira a matrícula deste aluno: \n");
      scanf("%d", &matricula);
      no = insereAlunoFinal(no, nome, matricula);
    }
    else {
      printf("\nOpção de inserção inválida inserida!\n");
    }
    printf("\nDeseja encerrar a inserção? (1 para sim, <>1 para não)\n");
    scanf("%d", &stop);
  }
  
  imprimeLista(no);


  system("pause");
  return 0;
}