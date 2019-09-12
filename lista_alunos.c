#include "lista.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

//Definição das structs que serão representadas por pointers opacos (TAD)

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

//==============================

//Funções do aluno
#pragma region Aluno

/**
 *  Função de criação de aluno (não adiciona na lista, apenas cria o nó a ser adicionado)
 * 
 *  Parâmetros: 
 *      int identificador - campo de identificação do aluno
 *      float horas_estudo - campo de horas de estudo do aluno
 *      float nota1 - primeira nota do aluno
 *      float nota2 - segunda nota do aluno
 * 
 *  Retorno: Aluno* - aluno criado
 */
Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->identificador = identificador;
    aluno->horas_estudo = horas_estudo;
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    return aluno;
}

/**
 *  Função que libera a memória de um TAD Aluno
 *  
 *  Parâmetros: 
 *      Aluno **aluno - pointer para o pointer (usado na main) que representa o aluno criado com aluno_criar()
 * 
 *  Retorno: void 
 */
void aluno_apagar(Aluno **aluno) {
    if (*aluno == NULL) return;
    
    free(*aluno);
    *aluno = NULL;
}

#pragma endregion


//========================


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
        soma += aluno_atual->horas_estudo;
        aluno_atual = aluno_atual->proximo;
        quantidade++;
    }

    if (quantidade == 0) {
        printf("\nHoras (Médias): Erro - nenhum aluno cadastrado!\n");
        return;
    }

    printf("\nHoras (Médias): %.2f. Total de alunos: %d alunos.\n", soma/quantidade, quantidade);    
}

void lista_liberar(ListaAlunos **lista_ptr){
    #define lista (*lista_ptr) //Legibilidade
    
    if (lista == NULL) return;

    Aluno *aluno_atual = lista->primeiro_aluno, *proximo_aluno;
    while (aluno_atual) {
        proximo_aluno = aluno_atual->proximo;
        aluno_apagar(&aluno_atual);
        aluno_atual = proximo_aluno;
    }

    free(lista);
    lista = NULL;

    #undef lista
}

int verifica_lista_vazia(ListaAlunos *vazia){
    if(vazia->primeiro_aluno == NULL) return 0;
    else return 1;
}

void lista_adicionar(ListaAlunos *lista, Aluno *aluno){

    if(lista->primeiro_aluno == NULL){
        lista->primeiro_aluno = aluno;
        aluno->proximo = NULL;
    }
    else{
        aluno->proximo = NULL;
        lista->ultimo_aluno->proximo = aluno;
    }
    lista->ultimo_aluno = aluno;
    lista->quantidade++;
}

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
        aluno_apagar(&p);
        verifica_mudanca = 1;
    }

    if(verifica_mudanca == 0) printf("\nNão foi possível encontrar o aluno com o identificador dado!\n");
}

void lista_imprimir_alunos(ListaAlunos *lista){

    if(lista->primeiro_aluno == NULL){
        printf("\nA lista atual se encontra vazia!!\n");
        return;
    }

    printf("\nDados do(s) aluno(s) da lista:\n\n");

    Aluno *atual = lista->primeiro_aluno;
    int i = 1;
    while(atual){
        printf("%d:\n   Identificador: %d\n   Horas de estudo: %.2f\n   Notas: %.2f || %.2f\n\n", i, atual->identificador,atual->horas_estudo, atual->nota1, atual->nota2);
        i++;
        atual = atual->proximo;
    }
}

void lista_imprimir_relatorio(ListaAlunos *relatorio){

    if(relatorio->primeiro_aluno == NULL){
        printf("\nA lista atual se encontra vazia!!\n");
        return;
    }

    printf("\nRegistro(s) do(s) aluno(s) da lista:\n");

    Aluno *atual = relatorio->primeiro_aluno;
    
    int i = 1;
    float media;
    while(atual){
        media = (atual->nota1 + atual->nota2)/2;
        printf("%d:\n  Identificador: %d\n  Média: %.2f\n", i, atual->identificador, media); 
        if(media >= 5) printf("---------->Aluno APROVADO<----------\n\n");
        else printf("---------->Aluno REPROVADO<----------\n\n");
        i++;
        atual = atual->proximo;
    }
}

#pragma endregion