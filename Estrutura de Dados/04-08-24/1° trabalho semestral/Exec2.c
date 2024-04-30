#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

int main(){

  int opcao = 1, flag = 0, count = 0, infoInsert, linhaInsert, colunaInsert, iBusca, jBusca, iSomatorio;
  Esparsa *mat;
  Lista *no;

  mat = NULL;
  mat = alocaMatrizEsparsa(mat);
  no = inicializaLista();

  printf("\nInsira, respectivamente, quantas linhas e quantas colunas a matriz esparsa deve ter: \n");
  scanf("%d %d", &mat->linhas, &mat->colunas);

  printf("\nPreencha os valores da matriz:\n");

  while (flag != 1 && count < mat->linhas*mat->colunas){
    printf("\nInsira o valor do elemento:\n");
    scanf("%d", &infoInsert);
    printf("\nInsira a linha em que o elemento será armazenado: (se as coordenadas inseridas já estiverem populadas o elemento anterior será sobrescrito)\n");
    scanf("%d", &linhaInsert);
    printf("\nInsira a coluna em que o elemento será armazenado: (se as coordenadas inseridas já estiverem populadas o elemento anterior será sobrescrito)\n");
    scanf("%d", &colunaInsert);
    if (linhaInsert < mat->linhas || colunaInsert < mat->colunas){
      no = insereNoFinal(no, infoInsert, linhaInsert, colunaInsert);
      count++;
    }
    else {
      printf("\nAs coordenadas inseridas não estão presentes na matriz! \n");
    }
    if (count <= mat->linhas*mat->colunas){
      printf("\nDeseja encerrar a inserção? (1 = sim; <> 1 = não) \n");
      scanf("%d", &flag);
    }
  }
  
  while (opcao != 0){
    printf("\nQual operação deseja realizar? (0 para encerrar)\n");
    printf("1 - Imprimir a matriz;\n");
    printf("2 - Buscar elemento na matriz;\n");
    printf("3 - Imprimir o somatório de determinada linha;\n");
    printf("4 - Calcular o percentual de elementos não-nulos inseridos na matriz;\n");
    scanf("%d", &opcao);
    switch(opcao){

      case 1:
        mat->prim = no;
        imprimeMatrizEsparsa(mat);
        break;

      case 2:
        printf("\nAgora, insira, respectivamente, a linha e a coluna de um elemento dentro dessa matriz para ele ser localizado: \n");
        scanf("%d %d", &iBusca, &jBusca);
        buscaElementoMatrizEsparsa(mat, iBusca, jBusca);
        break;

      case 3:
        printf("\nInsira a linha cujo somatório será calculado: \n");
        scanf("%d", &iSomatorio);
        printf("\nO somatório da %d° linha da matriz inserida é %.2f;\n", iSomatorio, calculaSomatorioLinhaMatrizEsparsa(mat, iSomatorio-1));
        break;

      case 4:
        printf("\n%.2f%% dos elementos da matriz esparsa são não-nulos;\n", calculaPercentualNaoNulosMatrizEsparsa(mat));
        break;

      default:
        printf("\n\n");
        break;

    }
  }
  
  freeMatrizEsparsa(mat);

  system("pause");
  return 0;
}