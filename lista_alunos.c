#include "lista_alunos.h"

#include <stdlib.h>

struct lista_alunos {
    int quantidade;
    Aluno *primeiro_aluno;
};

ListaAlunos* lista_criar() {
    ListaAlunos *lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista -> primeiro_aluno = NULL;
    lista -> quantidade = 0;
    return lista;
}

//TODO: Implementar funções definidas no .h