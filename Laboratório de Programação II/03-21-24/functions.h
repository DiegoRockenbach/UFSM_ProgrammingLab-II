#include <stdio.h>

struct municipio {
char* nome;
int populacao;
int** dados;
};
typedef struct municipio Municipio;

void relatorioQuantidadeMunSemNovosObitos(Municipio **vet, int quantMunicipios, int linha);

void relatorioObitosGeral(Municipio **vet, int quantMunicipios, int linha);

void relatorioConfirmadosGeral(Municipio **vet, int quantMunicipios, int linha);

void relatorioMunMenorMortalidade(Municipio **vet, int quantMunicipios, int linha);

void relatorioMunMaiorIncidencia(Municipio **vet, int quantMunicipios, int linha);

float calculaMortalidade100k(Municipio **vet, int linha, int i);

float calculaIncidencia100k(Municipio **vet, int linha, int i);

int contaObitos(Municipio **vet, int linha, int i);

int contaConfirmados(Municipio **vet, int linha, int i);

void imprimeListagemEpidemiologica(Municipio **vet, int linha, int quantMunicipios);

void imprimeMunicipio(Municipio **vet, int linha, int i);

int** alocaMatrizDados(int linha);

char* alocaVetorNome();

Municipio** alocaVetorPonteirosPontosDinamicos(int linha, int quantMunicipios);

void buffer();