#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno.h"

typedef struct lista_alunos ListaAlunos;

ListaAlunos* lista_criar(void);
void lista_adicionar(ListaAlunos*, Aluno*);
void lista_remover_aluno(ListaAlunos*, int);
void lista_imprimir_alunos(ListaAlunos*);
void lista_imprimir_relatorio(ListaAlunos*);
void lista_imprimir_tempo_medio_estudo(ListaAlunos*);
void lista_liberar(ListaAlunos **lista);

int verifica_lista_vazia(ListaAlunos *vazia);


#endif