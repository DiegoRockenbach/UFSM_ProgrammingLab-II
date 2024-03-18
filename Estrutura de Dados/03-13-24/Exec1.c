#include <stdio.h>
#include <stdlib.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y){

  int resp;

  if (x >= x0 && y >= y0 && x <= x1 && y <= y1){
    resp = 1;
  }
  else {
    resp = 0;
  }

  return resp;
}

int main(){

  int x0, y0, x1, y1, x, y, resp;

  printf("\nInforme, nesta sequência, os pontos x0 e y0 (que correspondem ao vértice inferior esquerdo de um determinado retângulo): \n");
  scanf("%d %d", &x0, &y0);
  printf("\nAgora, informe os pontos x1 e y1 (que correspondem ao vértice superior direito do mesmo retângulo): \n");
  scanf("%d %d", &x1, &y1);

  printf("\nAgora, informe um x e um y que serão analisados e classificados entre estando dentro ou fora do retângulo inserido: \n");
  scanf("%d %d", &x, &y);

  resp = dentro_ret(x0, y0, x1, y1, x, y);

  if (resp == 1){
    printf("\nO ponto das coordenadas fornecidas está DENTRO do retângulo;\n\n");
  }
  else {
    printf("\nO ponto das coordenadas fornecidas está FORA do retângulo;\n\n");
  }

  system("pause");
  return 0;
}