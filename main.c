#include <stdio.h>

#include "lista_alunos.h"
#include "aluno.h"

int main(int argc, char const *argv[])
{
    while (1) {
        printf("Menu principal. Escolha uma operação:\n\n");
        printf("(1) Inserir Registro\n");
        printf("(2) Remover Registro\n");
        printf("(3) Imprimir Registros\n");
        printf("(4) Relatório de Aprovações\n");
        printf("(5) Horas de estudo (Média)\n");
        printf("(6) Sair\n");
        printf(":");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //INSERIR REGISTRO
            break;

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
