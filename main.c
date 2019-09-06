#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "aluno.h"

void menu_exibir_opcoes() {
    printf("\n\nMenu principal. Escolha uma operação:\n\n");
    printf("(1) Inserir Registro\n");
    printf("(2) Remover Registro\n");
    printf("(3) Imprimir Registros\n");
    printf("(4) Relatório de Aprovações\n");
    printf("(5) Horas de estudo (Média)\n");
    printf("(6) Sair\n");
    printf(":");
}

Aluno* solicitar_registro() {
    int identificador;
    float horas_estudo, nota1, nota2;
    printf("Inserindo novo registro de aluno\n");
    printf("Digite o identificador do aluno: ");
    scanf("%d", &identificador);
    printf("Digite as horas de estudo do aluno: ");
    scanf("%f", &horas_estudo);
    printf("Digite as nota 1 do aluno: ");
    scanf("%f", &nota1);
    printf("Digite as nota 2 do aluno: ");
    scanf("%f", &nota2);
    Aluno *aluno = aluno_criar(identificador, horas_estudo, nota1, nota2);
    return aluno;
}

int solicitar_identificador_remocao(ListaAlunos *verifica) {
    int identificador;
    
    int vazia = verifica_lista_vazia(verifica);
    
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
    while (1) {
        menu_exibir_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {
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