#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

int main(){

  int i, j, k, quantMunicipios, linha, opcao = 0, flag = 0, stopWhile = 0;
  char buscaMunicipio[80];
  Municipio **vet;

  printf("\nInsira a quantidade de munícipios: \n");
  scanf("%d", &quantMunicipios);
  printf("\nInsira também a quantidade de linhas que cada matriz de dados dos municípios devem possuir: \n");
  scanf("%d", &linha);

  vet = alocaVetorPonteirosPontosDinamicos(linha, quantMunicipios);
  
  printf("\nAgora, insira os dados de cada município: \n");
  for (i = 0; i < quantMunicipios; i++){
    printf("\n\n%d° município: \n", i+1);
    printf("\nInsira o nome do município em questão: \n");
    buffer();
    fgets(vet[i]->nome, 80, stdin);
    printf("\nInsira a população do município em questão: \n");
    scanf("%d", &vet[i]->populacao);
    printf("\nAgora, insira a matriz de dados do município em questão: \n");
    for (j = 0; j < linha; j++){
      for (k = 0; k < 3; k++){
        if (k == 0){
          continue;
        }
        if (k == 1){
          printf("\nInsira a quantidade de confirmados para o %d° dia:\n", j+1);  
          scanf("%d", &vet[i]->dados[j][k]);
        }
        if (k == 2){
          printf("\nInsira a quantidade de óbitos que ocorreram no %d° dia:\n", j+1);  
          scanf("%d", &vet[i]->dados[j][k]);
        }
        
      }
    }
  }

  while (stopWhile == 0){
    printf("\nInsira o que deseja fazer ('1', '2', '3' ou '4'): \n");
    printf("1- Busca por nome de municípios: \n");
    printf("2- Listagem de municípios e dados epistemológicos gerais: \n");
    printf("3- Relatórios gerais: \n");
    printf("4- Encerrar o programa \n");
    scanf("%d", &opcao);
    switch (opcao){
    
      case 1:
        printf("\nInsira o nome pelo qual deseja buscar: \n");
        buffer();
        fgets(buscaMunicipio, 80, stdin);
        for (i = 0; i < quantMunicipios; i++){
          if (strcmp(vet[i]->nome, buscaMunicipio) == 0){
            flag = 1;
            imprimeMunicipio(vet, linha, i);
          }
          else {
            if (i == quantMunicipios-1 && flag != 1){
              printf("\nO nome inserido não foi encontrado na lista de municípios inseridos;\n\n");
            }
          }
        }
        flag = 0;
        break;
  
      case 2:
        imprimeListagemEpidemiologica(vet, linha, quantMunicipios);
        break;
  
      case 3:
        printf("\nRelatório 1:\n");
        relatorioMunMaiorIncidencia(vet, quantMunicipios, linha);
        printf("\nRelatório 2:\n");
        relatorioMunMenorMortalidade(vet, quantMunicipios, linha);
        printf("\nRelatório 3:\n");
        relatorioConfirmadosGeral(vet, quantMunicipios, linha);
        printf("\nRelatório 4:\n");
        relatorioObitosGeral(vet, quantMunicipios, linha);
        printf("\nRelatório 5:\n");
        relatorioQuantidadeMunSemNovosObitos(vet, quantMunicipios, linha);
        break;

      case 4:
        stopWhile = 1;
        break;
  
      default:
        printf("\nInserção inválida!\n");
    }
  }




  system("pause");
  return 0;
}