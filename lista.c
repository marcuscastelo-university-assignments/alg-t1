#include "lista.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

//Definição das structs que serão representadas por pointers opacos (TAD)

struct lista_alunos {
    int quantidade;
    Aluno *primeiro_aluno;
    Aluno *ultimo_aluno;
};

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
        soma += aluno_obter_horas(aluno_atual);
        aluno_atual = aluno_obter_proximo(aluno_atual);
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
        proximo_aluno = aluno_obter_proximo(aluno_atual);
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

bool verifica_lista_vazia(ListaAlunos *lista){
    if(lista->primeiro_aluno == NULL) return 0;
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

void lista_adicionar(ListaAlunos *lista, Aluno *aluno){

    if(lista->primeiro_aluno == NULL){
        lista->primeiro_aluno = aluno;
        aluno_definir_proximo(aluno, NULL);
    }
    else{
        aluno_definir_proximo(aluno, NULL);
        aluno_definir_proximo(lista->ultimo_aluno, aluno);
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
    Aluno *p = lista->primeiro_aluno;
    Aluno *auxiliar = NULL;

    while(p != NULL && aluno_obter_id(p) != id){
        auxiliar = p;
        p = aluno_obter_proximo(p);
    }

    if (p==NULL) 
        printf("\nNão foi possível encontrar o aluno com o identificador dado!\n");
    else {
        if(p == lista->primeiro_aluno){
            lista->primeiro_aluno = aluno_obter_proximo(p);
            aluno_definir_proximo(p, NULL);
        }
        else{
            aluno_definir_proximo(auxiliar, aluno_obter_proximo(p));
            aluno_definir_proximo(p, NULL);
        }

        if(p == lista->ultimo_aluno){
            lista->ultimo_aluno = auxiliar;
        }

        lista->quantidade--;
        aluno_apagar(&p);
    }
    
}


/**
 *  Função que imprime os dados dos alunos na lista
 *  Parâmetros:
 *      ListaAlunos *lista - pointer para o TAD lista
 *  
 *  Retrono: void (apenas printf na função)
 */
void lista_imprimir_alunos(ListaAlunos *lista){
    printf("\n");

    if(lista->primeiro_aluno == NULL){
        printf("ERRO: A lista atual se encontra vazia!!\n");
        return;
    }

    printf("Dados do(s) aluno(s) da lista:\n\n");

    Aluno *atual = lista->primeiro_aluno;
    int i = 1;
    while(atual){
        printf("%dº aluno: {\n\tIdentificador: %d\n\tHoras de estudo: %.2f\n\tNota 1: %.2f\n\tNota 2: %.2f\n}\n", i, aluno_obter_id(atual), aluno_obter_horas(atual), aluno_obter_nota1(atual), aluno_obter_nota2(atual));
        i++;
        atual = aluno_obter_proximo(atual);
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
    printf("\n");

    if(lista->primeiro_aluno == NULL){
        printf("ERRO: A lista atual se encontra vazia!!\n");
        return;
    }

    printf("Registro(s) do(s) aluno(s) da lista:\n");

    Aluno *aluno_atual = lista->primeiro_aluno;
    
    unsigned i = 1;
    float media;
    while(aluno_atual){
        media = (aluno_obter_nota1(aluno_atual) + aluno_obter_nota2(aluno_atual))/2;
        printf("%dº aluno: {\n\tIdentificador: %d\n\tMédia: %.2f\n}\n", i, aluno_obter_id(aluno_atual), media); 
       
        if(media >= 5) printf("---------->  Aluno APROVADO  <----------\n\n");
        else printf("---------->  Aluno REPROVADO  <----------\n\n");
        i++;
        aluno_atual = aluno_obter_proximo(aluno_atual);
    }
}

#pragma endregion