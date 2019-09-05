#include "lista.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int identificador;
    float horas_estudo;
    float nota1, nota2;

    Aluno *proximo;
};

struct lista_alunos {
    int quantidade;
    Aluno *primeiro_aluno;
};

//Funções do aluno
#pragma region Aluno

Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->identificador = identificador;
    aluno->horas_estudo = horas_estudo;
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    return aluno;
}

void aluno_apagar(Aluno *aluno) {
    free(aluno);
}

#pragma endregion

//Funções da lista
#pragma region Lista
ListaAlunos* lista_criar() {
    ListaAlunos *lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista -> primeiro_aluno = NULL;
    lista -> quantidade = 0;
    return lista;
}

void lista_imprimir_tempo_medio_estudo(ListaAlunos* lista) {
    Aluno *aluno_atual = lista->primeiro_aluno;
    float soma = 0; 
    unsigned quantidade = 0;

    while (aluno_atual) {
        aluno_atual = aluno_atual->proximo;
        quantidade++;
    }

    if (quantidade == 0) {
        printf("Horas (Médias): Erro - nenhum aluno cadastrado!\n");
        return;
    }

    //TODO: checar se essa é a mensagem que o prof quer
    printf("Horas (Médias): %.2f\n", soma/quantidade);    
}

void lista_liberar(ListaAlunos *lista){
    Aluno *aluno_atual = lista->primeiro_aluno, *proximo_aluno;
    while (aluno_atual) {
        proximo_aluno = aluno_atual->proximo;
        aluno_apagar(aluno_atual);
        aluno_atual = proximo_aluno;
    }
}
#pragma endregion

//TODO: Implementar funções definidas no .h