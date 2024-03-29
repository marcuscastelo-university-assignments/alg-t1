#include "aluno.h"
#include <stdlib.h>

struct aluno {
    int identificador;
    float horas_estudo;
    float nota1, nota2;
    Aluno *proximo;
};

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

/**
 * Função que retorna o próximo aluno da lista, mantendo a integridade do uso de um TAD
 * 
 * Parametros:
 *      Aluno * - aluno atual de referência para retornar o seu próximo
 * 
 * Retorno:
 *      Aluno * - proximo aluno
 */
Aluno *aluno_obter_proximo(Aluno *aluno){
    return aluno->proximo;
}

/**
 * Função que define o próximo aluno de uma lista, sem algum tipo de retorno
 * 
 * Parametros:
 *      Aluno * - atual aluno da lista para atribuir seu seguinte
 *      Aluno * - próximo aluno a ser atribuído/incluído na lista
 * 
 * Retorno:
 *      void
 */
void aluno_definir_proximo(Aluno *atual, Aluno *proximo){
    atual->proximo = proximo;
}

/**
 * Função que retorna o identificador de um dado aluno
 * 
 * Parametro:
 *      Aluno * - Aluno do qual se deseja encontrar seu identificador
 * 
 * Retorno:
 *      int - id do aluno
 */
int aluno_obter_id (Aluno *identificado){
    return identificado->identificador;
}

/**
 * Função que retorna as horas de estudo de um aluno
 * 
 * Parametro:
 *      Aluno * - Aluno do qual se deseja encontrar seu identificador
 * 
 * Retorno:
 *      float - horas de estudo
 */
float aluno_obter_horas(Aluno *aluno) {
    return aluno->horas_estudo;
}

/**
 * Funcao que retorna a nota 1 do aluno
 * 
 * Parametro:
 *      Aluno * - aluno atual
 * 
 * Retorno: float - nota 1
 */
float aluno_obter_nota1(Aluno *aluno){
    return aluno->nota1;
}

/**
 * Funcao que retorna a nota 2 do aluno
 * 
 * Parametro:
 *      Aluno * - aluno atual
 * 
 * Retorno: float - nota 2
 */
float aluno_obter_nota2(Aluno *aluno){
    return aluno->nota2;
}



/**
 *  Funções de definição de membros do TAD aluno
 *  Parâmetros:
 *      float - valor do parâmetro desejado
 *  Retorno: void
 */
void aluno_definir_horas_estudo(Aluno* aluno, float horas_estudo) {
    aluno->horas_estudo = horas_estudo;
}
void aluno_definir_nota1(Aluno* aluno, float nota1) {
    aluno->nota1 = nota1;
}
void aluno_definir_nota2(Aluno* aluno, float nota2) {
    aluno->nota2 = nota2;
}


#pragma endregion
