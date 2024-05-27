#ifndef __DATESH_INCLUDED__
#define __DATESH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct date_t {
  int dia;
  int mes;
  int ano;
}; typedef struct date_t Date;

int retornaDiaAtual();

int retornaMesAtual();

int retornaAnoAtual();

int difDiasEntreDatas(Date date1, Date date2);

#endif