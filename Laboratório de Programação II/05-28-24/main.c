#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
#include "bandejas.h"
#include "menu.c"

int main(){

  int opcaoMenu;
  FilaAlunos *filaExtNormal;
  FilaAlunos *filaExtPrioritaria;
  FilaAlunos *filaUnica;
  PilhaBandejas *bandejas;

  filaExtNormal = NULL;
  filaExtPrioritaria = NULL;
  filaUnica = NULL;
  bandejas = NULL;

  printf("\nBem vindos ao sistema de gerenciamento de flas do RU!\n");

  while (1){
    opcaoMenu = imprimeMenu();
    if (opcaoMenu == 1){
      filaExtNormal = insereAlunoFilasExternas(filaExtNormal);
    }
    else if (opcaoMenu == 2){
      filaExtPrioritaria = insereAlunoFilasExternas(filaExtPrioritaria);
    }
    else if (opcaoMenu == 3){
      filaUnica = geraFilaUnica(filaUnica, &filaExtNormal, &filaExtPrioritaria);
    }
    else if (opcaoMenu == 4){
      bandejas = repoeBandejas(bandejas);
      printf("\n\n");
      imprimeBandejas(bandejas);
    }
    else if (opcaoMenu == 5){
      if (bandejas == NULL){
        printf("\nNão é possível a fila única andar pois não há bandejas na pilha; \n");
      }
      if (filaUnica == NULL){
        printf("\nNão é possível retirar bandejas da pilha pois não há nenhum aluno na fila única; \n");
      }
      else if (bandejas != NULL && filaUnica != NULL){
        alunoRetiraBandeja(bandejas);
      }
    }
    else if (opcaoMenu == 6){
      if (filaUnica == NULL){
        printf("\nRemoção falhou! Não há nenhum aluno na fila única; \n");
      }
      else {
        filaUnica = removeAlunoFila(filaUnica);
      }
    }
    else if (opcaoMenu == 7){
      imprimeTodasFilas(filaUnica, filaExtNormal, filaExtPrioritaria);
    }
    else if (opcaoMenu == 8){
      return 0;
    }
    else {
      printf("\nA opção inserida foi inválida! \n");
    }
  }

  system("pause");
  return 0;
}