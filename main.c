#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "aluno.h"

/**
 * Função simples que agrupa comandos de exibição do menu com o objetivo de 
 * deixar o código mais claro e limpo
 * 
 * Parâmetros: nenhum
 * 
 * Retorna void
 */
void menu_exibir_opcoes() {
    printf("\nMenu principal. Escolha uma operação:\n\n");
    printf("(1) Inserir Registro\n");
    printf("(2) Remover Registro\n");
    printf("(3) Imprimir Registros\n");
    printf("(4) Relatório de Aprovações\n");
    printf("(5) Médias de horas de estudo\n");
    printf("(6) Sair\n");
    printf(":");
}

/**
 * Função que agrupa comandos para solicitar dados dos alunos 
 * com o objetivo de deixar o código mais claro e limpo
 * 
 * Parâmetros: nenhum
 * 
 * Retorno: Aluno* - pointer para o TAD aluno criado com as informações solicitadas
 */
Aluno* solicitar_registro() {
    int identificador;
    float horas_estudo = -1;
    float nota1 = -1;
    float nota2 = -1;

    //Solicitando dados (com verificação de validade)

    printf("Inserindo novo registro de aluno\n");
    printf("Digite o identificador do aluno: ");
    scanf("%d", &identificador);
    while(horas_estudo < 0){
        printf("Digite as horas de estudo do aluno: ");
        scanf("%f", &horas_estudo);
        if(horas_estudo < 0) printf("Quantidade digitada inválida. ");
    }
    while(nota1 < 0){
        printf("Digite a nota 1 do aluno: ");
        scanf("%f", &nota1);
        if(nota1 < 0) printf("Nota digitada inválida. ");
    }
    while(nota2 < 0){
        printf("Digite a nota 2 do aluno: ");
        scanf("%f", &nota2);
        if(nota2 < 0) printf("Nota digitada inválida. ");
    }

    //Criação e retorno do TAD aluno

    Aluno *aluno = aluno_criar(identificador, horas_estudo, nota1, nota2);
    return aluno;
}

/**
 * Função que agrupa comandos para solicitar o identificador do aluno para a operação de remoção
 * com o objetivo de deixar o código mais claro e limpo
 * 
 * Parâmetros: ListaAlunos *lista - pointer para a lista (verifica se a lista está vazia e exibe erro nesse caso)
 * 
 * Retorno: int - identificador digitado ou -1 em caso de lista vazia
 */
int solicitar_identificador_remocao(ListaAlunos *lista) {
    int identificador;
    
    int vazia = verifica_lista_vazia(lista);
    
    if(vazia == 1){
        printf("Removendo registro de aluno\n");
        printf("Digite o identificador do aluno que deseja remover: ");
        scanf("%d", &identificador);
        return identificador;
    }
    else{
        printf("\nAtual instância da lista se encontra vazia!!\n");
        return -1;
    }
}


//TODO: formatar melhor a saida das funções.
int main(int argc, char const *argv[])
{
    ListaAlunos *lista_alunos;
    lista_alunos = lista_criar();

    int opcao;

    //Mantém o menu em loop, do qual só se sai através da opção 6.
    while (1) {
        menu_exibir_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {

            //Usando chaves (bloco), pois em um switch padrão, não é permitido a declaração de variáveis
            case 1: {
                Aluno *novo_aluno = solicitar_registro();
                lista_adicionar(lista_alunos, novo_aluno);
                break;
            }
            
            case 2:{
                int identificador = solicitar_identificador_remocao(lista_alunos);
                if(identificador != -1) lista_remover_aluno(lista_alunos, identificador);
                break;
            }
                
            case 3:
                lista_imprimir_alunos(lista_alunos);
                break;

            case 4: 
                lista_imprimir_relatorio(lista_alunos);
                break;

            case 5:
                lista_imprimir_tempo_medio_estudo(lista_alunos);
                break;

            case 6:
                lista_liberar(lista_alunos);
                exit(0);
                break;
            
            default:
                printf("Opção escolhida é invalida!");
                break;
        }
    }

    return 0;
}