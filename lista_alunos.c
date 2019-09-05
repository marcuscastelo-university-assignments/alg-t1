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
    Aluno *ultimo_aluno;
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

int verifica_lista_vazia(ListaAlunos *vazia){
    if(vazia->primeiro_aluno == NULL) return 0;
    else return 1;
}

//Tentei implementar conforme os slides do Ruds
void lista_adicionar(ListaAlunos *lista, Aluno *aluno){

    if(lista->primeiro_aluno == NULL){
        lista->primeiro_aluno = aluno;
        lista->ultimo_aluno = aluno;
        aluno->proximo = NULL;
    }
    else{
        aluno->proximo = NULL;
        lista->ultimo_aluno->proximo = aluno;
    }
    lista->quantidade++;
}

//Tentei implementar conforme os slides do Ruds
//Remove apenas o primeiro aluno, caso haja id's duplicadas
void lista_remover_aluno(ListaAlunos *lista, int id){

    int verifica_mudanca = 0;
    Aluno *p = lista->primeiro_aluno;
    Aluno *auxiliar = NULL;

    while(p != NULL && (p->identificador) != id){
        auxiliar = p;
        p = p->proximo;
    }

    if(p!= NULL){
        if(p == lista->primeiro_aluno){
            lista->primeiro_aluno = p->proximo;
            p->proximo = NULL;
        }
        else{
            auxiliar->proximo = p->proximo;
            p->proximo = NULL;
        }

        if(p == lista->ultimo_aluno){
            lista->ultimo_aluno = auxiliar;
        }

        lista->quantidade--;
        free(p);
        verifica_mudanca = 1;
    }

    if(verifica_mudanca == 0) printf("Não foi possível encontrar aluno com o identificador dado!\n");
}

void lista_imprimir_alunos(ListaAlunos *lista){

    if(lista->primeiro_aluno == NULL){
        printf("A lista atual se encontra vazia!!\n");
        return;
    }

    printf("Dados do(s) aluno(s) da lista:\n");

    Aluno *atual = lista->primeiro_aluno;
    int i = 1;
    while(atual){
        printf("%d:\nIdentificador: %d\nNotas: %.2f || %.2f\nHoras de estudo: %.2f\n\n", i, atual->identificador, atual->nota1, atual->nota2, atual->horas_estudo);
        i++;
        atual = atual->proximo;
    }
}

#pragma endregion

//TODO: Implementar funções definidas no .h