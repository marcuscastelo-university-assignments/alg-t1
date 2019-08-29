#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

//TODO: Comentar as funções

Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2);
void aluno_atualizar_horas(Aluno*, int horas);
void aluno_atualizar_nota1(Aluno*, int nota1);
void aluno_atualizar_nota2(Aluno*, int nota2);
void aluno_apagar(Aluno*);

#endif