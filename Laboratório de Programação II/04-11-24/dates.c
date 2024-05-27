#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dates.h"

int retornaDiaAtual(){
  struct tm *p;
  time_t seconds;

  time(&seconds);
  p = localtime(&seconds);

  return p->tm_mday;
}

int retornaMesAtual(){
  struct tm *p;
  time_t seconds;

  time(&seconds);
  p = localtime(&seconds);

  return p->tm_mon + 1;
}

int retornaAnoAtual(){
  struct tm *p;
  time_t seconds;

  time(&seconds);
  p = localtime(&seconds);

  

  return (p->tm_year + 1900) % 100;
}

int difDiasEntreDatas(Date date1, Date date2){  // código template provido pela professora
    
    int dias1 = date1.ano * 365 + date1.dia;
    int dias2 = date2.ano * 365 + date2.dia;

    // Adicionar dias extras para os anos bissextos
    dias1 += date1.ano / 4 - date1.ano / 100 + date1.ano / 400;
    dias2 += date2.ano / 4 - date2.ano / 100 + date2.ano / 400;

    // Adicionar dias para os meses
    int mesdias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.mes; i++) {
        dias1 += mesdias[i];
    }
    for (int i = 1; i < date2.mes; i++) {
        dias2 += mesdias[i];
    }

    // Considerar anos bissextos
    if (date1.mes <= 2 && (date1.ano % 4 == 0 && (date1.ano % 100 != 0 || date1.ano % 400 == 0))) {
        dias1--;
    }
    if (date2.mes <= 2 && (date2.ano % 4 == 0 && (date2.ano % 100 != 0 || date2.ano % 400 == 0))) {
        dias2--;
    }

    // Calcular a diferença em dias
    int difference = dias2 - dias1;
    
    return difference;
}
