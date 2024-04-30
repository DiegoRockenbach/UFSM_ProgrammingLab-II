#include <stdio.h>
#include <stdlib.h>

// EXEC 1

struct diagonal {
  int ordem;
  int *v;
};
typedef struct diagonal Diagonal;

int* alocaVetor(int ordem){

  int *vet;

  vet = (int*) malloc(ordem*sizeof(int));
  if (vet==NULL){
    printf("Memória insuficiente.\n");
    return NULL;
  }

  return vet;
}

void imprimeMatrizDiagonal(Diagonal mat){

  int i, j;

  printf("\n\n");
  for (i = 0; i < mat.ordem; i++){
    for (j = 0; j < mat.ordem; j++){
      if (i == j){
        printf("%d ", mat.v[i]);
      }
      else {
        printf("0 ");
      }
    }
    printf("\n");
  }

}



// EXEC 2

struct lista { 
  int linha;
  int coluna;
  int info;
  struct lista *prox;
}; 
typedef struct lista Lista;

struct esparsa {
  int linhas;
  int colunas;
  Lista *prim;
}; 
typedef struct esparsa Esparsa;

Lista* inicializaLista(void){
  return NULL;
}

Lista* insereNoFinal(Lista *l, int valor, int linha, int coluna){
  
  Lista *novo, *p;
  
  novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  novo->info = valor;
  novo->linha = linha;
  novo->coluna = coluna;
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

Esparsa* alocaMatrizEsparsa(){
  
  Esparsa *mat;

  mat = (Esparsa*) malloc(sizeof(Esparsa));
  if (mat == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  mat->prim = (Lista*) malloc(sizeof(Lista));
  if (mat->prim == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }

  return mat;
}

void imprimeMatrizEsparsa(Esparsa *mat){

  int i, j;
  Lista *p;

  printf("\n\n");
  p = mat->prim;
  for (i = 0; i < mat->linhas; i++){
    for (j = 0; j < mat->colunas; j++){
      if (p->linha == i && p->coluna == j){
        printf("%d ", p->info);
        if (p->prox != NULL){
          p = p->prox;
        }
      }
      else {
        printf("0 ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void buscaElementoMatrizEsparsa(Esparsa *mat, int i, int j){

  Lista *p;

  p = mat->prim;
  while (p != NULL) {
    if (p->linha == i && p->coluna == j){
      printf("\nO elemento presente nas coordenadas inseridas é %d; \n\n", p->info);
      return NULL;
    }
    else{
      p = p->prox;
    }
  }
  
  printf("\nO elemento encontrado nas coordenadas inseridas é 0; \n\n");
}

float calculaSomatorioLinhaMatrizEsparsa(Esparsa *mat, int iSomatorio){

  float resultado = 0;
  Lista *p;

  p = mat->prim;
  while (p != NULL) {
    if (p->linha == iSomatorio){
      resultado = resultado + p->info;
    }
    p = p->prox;
  }

  return resultado;
}

float calculaPercentualNaoNulosMatrizEsparsa(Esparsa *mat){

  int count = 0;
  float percent = 0;
  Lista *p;

  p = mat->prim;
  while (p != NULL) {
    count++;
    p = p->prox;
  }
  
  percent = (count*100)/(mat->linhas*mat->colunas);

  return percent;
}

void freeMatrizEsparsa(Esparsa *mat){

  Lista *p;

  p = mat->prim;
  while (p != NULL){
    free(p);
    if (p->prox != NULL){
      p = p->prox;
    }
  }
  free(mat);

}



// EXEC 3

struct identidade { 
  int ordem;
  Lista *prim;
}; 
typedef struct identidade Identidade;

/* struct lista {                               Declarada na seção do Exec2
  int linha;
  int coluna;
  int info;
  struct lista *prox;
}; 
typedef struct lista Lista; */

Identidade* alocaMatrizIdentidade(){
  
  Identidade *mat;

  mat = (Identidade*) malloc(sizeof(Identidade));
  if (mat == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }
  mat->prim = (Lista*) malloc(sizeof(Lista));
  if (mat->prim == NULL){
    printf("\nErro de alocação de memória!\n\n");
    system("pause");
    return NULL;
  }

  return mat;
}

void imprimeMatrizIdentidade(Identidade *mat){

  int i, j;
  Lista *p;

  printf("\n\n");
  p = mat->prim;
  for (i = 0; i < mat->ordem; i++){
    for (j = 0; j < mat->ordem; j++){
      printf("%d ", p->info);
      p = p->prox;
    }
    printf("\n");
  }
  printf("\n");
}

void verificaMatrizIdentidade(Identidade *mat){

  int i, j, flag = 1;
  Lista *p;

  printf("\n");
  p = mat->prim;
  for (i = 0; i < mat->ordem; i++){
    for (j = 0; j < mat->ordem; j++){
      if ((i == j && p->info == 1) || (i != j && p->info == 0)){
        p = p->prox;
        continue;
      }
      else if (p->info == 1 && i != j){
        flag = 0;
        printf("\nO número %d, localizado nas coordenadas [%d][%d], é 1 porém não está localizado na diagonal principal da matriz; \n", p->info, i, j);
      }
      else if (p->info != 1 && i == j){
        flag = 0;
        printf("\nO número %d, localizado nas coordenadas [%d][%d], apesar de estar localizado na diagonal principal da matriz é diferente de 1; \n", p->info, i, j);
      }
      else if (p->info != 1 && i != j){
        flag = 0;
        printf("\nO número %d, localizado nas coordenadas [%d][%d], não é 1 e também não está localizado na diagonal principal da matriz; \n", p->info, i, j);
      }
      if (p->prox != NULL){
        p = p->prox;
      }
    }
  }

  if (flag == 1){
    printf("\nA matriz inserida é uma matriz identidade! \n\n");
  }
  else {
    printf("\nPortanto, a matriz inserida NÃO é uma matriz identidade! \n\n");
  }
}



// EXEC 4

int ***aloca_matriz(int m, int n, int z) {
    int ***mat;
    int i, j;
    mat = (int ***) malloc(m * sizeof(int **)); //aloca o vetor das linhas
    for (i = 0; i < m; i++) {
        mat[i] = (int **) malloc(n * sizeof(int *));//aloca o vetor das colunas
        for (j = 0; j < n; j++) {
            mat[i][j] = (int *) malloc(z * sizeof(int)); //aloca o vetor da profundidade
        }
    }

    if (mat == NULL) { //teste de erro de alocação
        printf("ATENÇÃO: Memoria não pode ser alocada por falta de espaço livre.\n");
    }
    return mat;

}

void preenche_matriz(int m, int n, int z, int ***mat) {
    printf("Preencha o valor de cada celula da matriz: \n\n");
    /*ao meu ver, fazer o for em profundiadade->linha->coluna fica mais visualizar
     o preenchimento da matriz*/
    for (int k = 0; k < z; k++) { //profundiadade
        for (int i = 0; i < m; i++) { //linha
            for (int j = 0; j < n; j++) { //coluna
                printf("mat[%d][%d][%d]:", i,j,k);
                scanf("%d", &mat[i][j][k]);
            }
        }
        printf("\n");
    }
}

void imprime_matriz(int m, int n, int z, int ***mat) {
    printf("Matriz: \n\n");
    /*segui a mesma linha que fiz com o preenchimento, pois, fica mais organizado e visual no print */
    for (int k = 0; k < z; k++) { //profundidade
        for (int i = 0; i < m; i++) { //linha
            for (int j = 0; j < n; j++) { //coluna
                printf("%03d ", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void libera_matriz(int m, int n, int ***mat) { 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(mat[i][j]); //libera a profundidade
        }
        free(mat[i]); //libera as colunas
    }
    free(mat); //libera as linhas
}