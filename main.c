#include <stdio.h>

int main(int argc, char const *argv[])
{
    char opcao;
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


    return 0;
}
