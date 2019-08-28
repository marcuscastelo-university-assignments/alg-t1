#include "aluno.h"

#include <stdlib.h>

struct aluno {
    int identificador;
    float horas_estudo;
    float nota1, nota2;

    Aluno *proximo;
};

Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->identificador = identificador;
    aluno->horas_estudo = horas_estudo;
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    return aluno;
}