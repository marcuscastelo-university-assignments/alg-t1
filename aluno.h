#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

//TODO: Comentar as funções

//Funcao que cria o ponteiro do TAD aluno e retorna-o para referencia
Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2);

void aluno_atualizar_horas(Aluno*, int horas);
int aluno_obter_horas(Aluno*);

void aluno_atualizar_nota1(Aluno*, int nota1);
int aluno_obter_nota1(Aluno*);

void aluno_atualizar_nota2(Aluno*, int nota2);
int aluno_obter_nota2(Aluno*);

Aluno *aluno_obter_proximo(Aluno*);
void aluno_definir_proximo(Aluno*, Aluno*);

//Funcao utilizada para apagar/dar free no ponteiro do TAD aluno
void aluno_apagar(Aluno**);

#endif