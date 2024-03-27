#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void relatorioQuantidadeMunSemNovosObitos(Municipio **vet, int quantMunicipios, int linha){

  int i, j, k, quant = 0;

  for (i = 0; i < quantMunicipios; i++){
    if (vet[i]->dados[linha-1][2] == 0){
      quant++;
    }
  }

  printf("\nA quantidade de municípios sem novos óbitos é de %d;\n", quant);

}

void relatorioObitosGeral(Municipio **vet, int quantMunicipios, int linha){

  int i, totalObitos = 0;

  for (i = 0; i < quantMunicipios; i++){
    totalObitos = totalObitos + contaObitos(vet, linha, i);
  }

  printf("\nA quantidade total de óbitos é de %d;\n", totalObitos);

}

void relatorioConfirmadosGeral(Municipio **vet, int quantMunicipios, int linha){

  int i, totalConfirmados = 0;

  for (i = 0; i < quantMunicipios; i++){
    totalConfirmados = totalConfirmados + contaConfirmados(vet, linha, i);
  }

  printf("\nA quantidade total de confirmados é de %d;\n", totalConfirmados);

}

void relatorioMunMenorMortalidade(Municipio **vet, int quantMunicipios, int linha){

  int i, store = 0;
  float mortalidadeAtual, menorMortalidade = 999999;

  for (i = 0; i < quantMunicipios; i++){
    mortalidadeAtual = calculaMortalidade100k(vet, linha, i);
    if (mortalidadeAtual < menorMortalidade){
      menorMortalidade = mortalidadeAtual;
      store = i;
    }
  }

  printf("\nO município com menor mortalidade é %s;\n", vet[store]->nome);

}

void relatorioMunMaiorIncidencia(Municipio **vet, int quantMunicipios, int linha){

  int i, store = 0;
  float incidenciaAtual, maiorIncidencia = 0;

  for (i = 0; i < quantMunicipios; i++){
    incidenciaAtual = calculaIncidencia100k(vet, linha, i);
    if (incidenciaAtual > maiorIncidencia){
      maiorIncidencia = incidenciaAtual;
      store = i;
    }
  }

  printf("\nO município com maior incidência é %s;\n", vet[store]->nome);

}

float calculaMortalidade100k(Municipio **vet, int linha, int i){

  float mortalidade100k;
  int totalObitos;

  totalObitos = contaObitos(vet, linha, i);
  mortalidade100k = (totalObitos*100000)/vet[i]->populacao;

  return mortalidade100k;
}

float calculaIncidencia100k(Municipio **vet, int linha, int i){

  float incidencia100k;
  int totalConfirmados;

  totalConfirmados = contaConfirmados(vet, linha, i);
  incidencia100k = (totalConfirmados*100000)/vet[i]->populacao;

  return incidencia100k;
}

int contaObitos(Municipio **vet, int linha, int i){

  int j, k, totalObitos = 0;

  for (j = 0; j < linha; j++){
    for (k = 0; k < 3; k++){
      if (k == 2){
        totalObitos = totalObitos+vet[i]->dados[j][k];
      }
    }
  }

  return totalObitos;
}

int contaConfirmados(Municipio **vet, int linha, int i){

  int j, k, totalConfirmados = 0;

  for (j = 0; j < linha; j++){
    for (k = 0; k < 3; k++){
      if (k == 1){
        totalConfirmados = totalConfirmados+vet[i]->dados[j][k];
      }
    }
  }

  return totalConfirmados;
}

void imprimeListagemEpidemiologica(Municipio **vet, int linha, int quantMunicipios){

  int i;

  for (i = 0; i < quantMunicipios; i++){
    printf("\n\nNome: %s;\n\n", vet[i]->nome);
    printf("Total de confirmados: %d;\n", contaConfirmados(vet, linha, i));
    printf("Total de novos confirmados (último dia): %d;\n", vet[i]->dados[linha-1][1]);
    printf("Incidência por 100 mil habitantes: %.2f;\n", calculaIncidencia100k(vet, linha, i));
    printf("Total de óbitos: %d;\n", contaObitos(vet, linha, i));
    printf("Total de novos óbitos (último dia): %d;\n", vet[i]->dados[linha-1][2]);
    printf("Mortalidade por 100 mil habitantes: %.2f;\n", calculaMortalidade100k(vet, linha, i));
  }

  printf("\n\n");

}

void imprimeMunicipio(Municipio **vet, int linha, int i){

  int j, k;

  printf("\nNome: %s;\n", vet[i]->nome);
  printf("População: %d;\n", vet[i]->populacao);
  printf("Matriz de dados: \n");
  for (j = 0; j < linha; j++){
    for (k = 0; k < 3; k++){
      printf("%d ", vet[i]->dados[j][k]);
    }
    printf("\n");
  }
  printf("\n\n");

}

int** alocaMatrizDados(int linha){

  int i;
  int **mat;

  mat = (int**) malloc(linha*sizeof(int*));
  if (mat==NULL){
    printf("Memória insuficiente.\n");
    return NULL;
  }
  for (i = 0; i < linha; i++){
    mat[i] = (int*) malloc(3*sizeof(int));
    if (mat[i]==NULL){
      printf("Memória insuficiente.\n");
      return NULL;
    }
  }

  return mat;

}

char* alocaVetorNome(){

  char *vet;

  vet = (char*) malloc(80*sizeof(char));
  if (vet==NULL){
    printf("Memória insuficiente.\n");
    return NULL;
  }

  return vet;

}

Municipio** alocaVetorPonteirosPontosDinamicos(int linha, int quantMunicipios){

  int i, j, k, count = 1;
  Municipio **vet;

  vet = (Municipio**) malloc(quantMunicipios * sizeof(Municipio*));
  if (vet == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  for (i = 0; i < quantMunicipios; i++){
    vet[i] = (Municipio*) malloc(sizeof(Municipio));
    if (vet == NULL){
      printf("\nErro de alocação de memória!\n\n");
      system("pause");
      return NULL;
    }

    vet[i]->nome = alocaVetorNome();
    vet[i]->dados = alocaMatrizDados(linha);

    for (j = 0; j < linha; j++){
      for (k = 0; k < 3; k++){
        if (k == 0){
          vet[i]->dados[j][k] = count;
          count++;
        }
      }
    }
  }

  return vet;

}

void buffer(){
  
  int c;
  while((c = getchar()) != '\n' && c != EOF) {}

}