#include <stdio.h>

#include "lista_alunos.h"
#include "aluno.h"

void menu_exibir_opcoes() {
    printf("Menu principal. Escolha uma operação:\n\n");
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
    printf("Inserindo novo registro de aluno:\n");
    printf("Digite o identificador do aluno: ");
    scanf("%d", &identificador);
    printf("Digite as horas de estudo do aluno: ");
    scanf("%f", &horas_estudo);
    printf("Digite as nota 1 do aluno: ");
    scanf("%f", &nota1);
    printf("Digite as nota 2 do aluno: ");
    scanf("%f", &nota2);
    Aluno *aluno;// = aluno_criar(identificador, horas_estudo, nota1, nota2);
    return aluno;
}

int main(int argc, char const *argv[])
{
    int opcao;
    while (1) {
        menu_exibir_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: {
            Aluno *novo_aluno = solicitar_registro();
            break;
        }
        

        case 2:
            //REMOVER REGISTRO
            break;

        case 3:
            //IMPRIMIR REGISTROS
            break;

        case 4: 
            //RELATÓRIO DE APROVACAO
            break;

        case 5:
            //HORAS DE ESTUDO (MÉDIA)
            break;

        case 6:
            //SAIR
            break;
        
        default:
            //OPCAO INVALIDA
            break;
        }
    }



    return 0;
}
