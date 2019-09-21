#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno.h"

typedef struct lista_alunos ListaAlunos;
typedef char bool;

//Funcao que cria o ponteiro do TAD lista_aluno e o retorna para referencia
ListaAlunos* lista_criar(void);

//Funcao que adiciona um ponteiro aluno, no fim, para a lista encadeada
void lista_adicionar(ListaAlunos*, Aluno*);

//Funcao que remove um aluno da lista encadeada e a reajusta, fazendo busca pelo seu identificador
void lista_remover_aluno(ListaAlunos*, int);

//Funcao que imprime a lista_aluno, ou seja, todos os dados
void lista_imprimir_alunos(ListaAlunos*);

//Funcao que imprime o relatorio de cada aluno na lista, listando suas notas, media e se foi aprovado ou não
void lista_imprimir_relatorio(ListaAlunos*);

//Funcao que imprime o tempo medio de estudo de todos os alunos cadastrados na lista
void lista_imprimir_tempo_medio_estudo(ListaAlunos*);

//Funcao que apaga a lista, recebendo duplo pointer para apagar os aluno e, em seguida, o proprio ponteiro da lista, mantendo o information hiding
void lista_liberar(ListaAlunos **);

//Funcao que verifica se a lista dada esta vazia, retornando um inteiro que determinara os passos seguintes
bool verifica_lista_vazia(ListaAlunos *vazia);

#endif