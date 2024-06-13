#ifndef __FILASH_INCLUDED__
#define __FILASH_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FilaAlunos_t{
  int ticket;
  struct FilaAlunos_t *prox;
}; typedef struct FilaAlunos_t FilaAlunos;

FilaAlunos* insereAlunoFilasExternas(FilaAlunos *fila);

FilaAlunos* insereAlunoFilaUnica(FilaAlunos *filaUnica, FilaAlunos *filaExt);

bool isFilaUnicaCheia(FilaAlunos *filaUnica);

FilaAlunos* geraFilaUnica(FilaAlunos *filaUnica, FilaAlunos **filaExtNormal, FilaAlunos **filaExtPrioritaria);

FilaAlunos* removeAlunoFila(FilaAlunos *fila);

void imprimeFila(FilaAlunos *fila);

void imprimeTodasFilas(FilaAlunos *filaUnica, FilaAlunos *filaExtNormal, FilaAlunos *filaExtPrioritaria);

#endif