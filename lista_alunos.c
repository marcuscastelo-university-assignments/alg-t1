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

/**
 *  Função que inicializa a lista, fazendo o malloc do bloco que contem informações
 *  sobre a lista, como o nó inicial, tamanho, etc.
 * 
 *  Parâmetros: nenhum:
 *  Retorno: ListaAlunos* - pointer para o TAD lista criado
 */
ListaAlunos* lista_criar() {
    ListaAlunos *lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista -> primeiro_aluno = NULL;
    lista -> quantidade = 0;
    return lista;
}

/**
 *  Função responsável por imprmir o tempo médio de estudo
 *  Calcula a média dos tempos de estudo de todos os alunos na lista
 *  e exibe-a.
 * 
 *  Parâmteros:
 *      ListaAlunos *lista - pointer para o TAD lista
 * 
 *  Retorno: void
 */ 
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


/**
 *  Função que libera o espaço na heap usado pelo TAD lista
 *  e seus itens.
 * 
 *  Parâmetros: 
 *      ListaAlunos **lista_ptr - pointer para o pointer que aponta para o TAD
 *      OBS: é um double pointer para que seja possível redefinir seu valor a NULL
 * 
 *  Retorno: void
 */
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


/**
 *  Função que verifica se a lista está vazia
 * 
 *  Parâmetros:
 *      ListaAlunos *vazia - pointer para o TAD lista referida
 * 
 *  Retorno: bool - typedef para um tipo representando 0 ou 1
 *      OBS: (0 = lista não vazia, 1 = lista vazia)
 */

bool verifica_lista_vazia(ListaAlunos *vazia){
    if(vazia->primeiro_aluno == NULL) return 0;
    else return 1;
}

/**
 *  Função que adiciona um aluno na lista
 *  OBS: o aluno já deve ter sido criado com a função de criação de aluno.
 *  OBS2: o aluno é um TAD, portanto apenas a sua referência é adicionada na lista (sem cópias),
 *  sendo o aluno, portanto, modificável pelo pointer inicial.
 * 
 *  Parâmetros:
 *      ListaAlunos *lista - pointer para o TAD lista
 *      Aluno *aluno - aluno já criado, a ser adicionado na lista
 * 
 *  Retorno: void (nunca vai haver problemas com lista cheia, porque o aluno já foi alocado)
 */

//TODO: verificar se é melhor fazer uma cópia do aluno, por causa da remoção
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

/**
 *  Função que remove o aluno da lista
 *  
 *  Parâmetros:
 *      ListaAlunos *lista - pointer para o TAD lista
 *      int id - id do aluno que se deseja remover
 *  
 *  Retorno: void
 */
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


/**
 *  Função que imprime os dados dos alunos na lista
 *  Parâmetros:
 *      ListaAlunos *lista - pointer para o TAD lista
 *  
 *  Retrono: void (apenas printf na função)
 */
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


/**
 *  Função de impressão de relatórios da lista de alunos
 * 
 *  Parâmetros:
 *      ListaAlunos *lista - pointer para o TAD lista
 * 
 *  Retorno: void (apenas printf)
 */
void lista_imprimir_relatorio(ListaAlunos *lista){

    if(lista->primeiro_aluno == NULL){
        printf("\nA lista atual se encontra vazia!!\n");
        return;
    }

    printf("\nRegistro(s) do(s) aluno(s) da lista:\n");

    Aluno *atual = lista->primeiro_aluno;
    
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