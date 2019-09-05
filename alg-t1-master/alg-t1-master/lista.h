#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno.h"

typedef struct lista_alunos ListaAlunos;

//TODO: Comentar as funções

ListaAlunos* lista_criar(void);
void lista_adicionar(ListaAlunos *lista, Aluno *aluno);
void lista_remover_aluno(ListaAlunos *lista, int id);
void lista_imprimir_alunos(ListaAlunos *lista);
void lista_imprimir_relatorio(ListaAlunos*);
void lista_imprimir_tempo_medio_estudo(ListaAlunos*);
void lista_liberar(ListaAlunos*);

int verifica_lista_vazia(ListaAlunos *vazia);

#endif