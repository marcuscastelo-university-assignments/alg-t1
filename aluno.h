#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

//Função que cria o ponteiro do TAD aluno e retorna-o para referência
Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2);

//Função que permite a atualização das horas de estudo de um aluno
void aluno_definir_horas_estudo(Aluno*, float horas_estudo);
float aluno_obter_horas(Aluno*);

//Função que permite definir a nota 1 do aluno
void aluno_definir_nota1(Aluno*, float nota1);
float aluno_obter_nota1(Aluno*);

//Função que permite definir a nota 2 do aluno
void aluno_definir_nota2(Aluno*, float nota2);
float aluno_obter_nota2(Aluno*);

//Função que retorna o proximo aluno da lista, mantendo o objetivo de se usar um TAD (information hiding)
Aluno *aluno_obter_proximo(Aluno*);
void aluno_definir_proximo(Aluno*, Aluno*);

//Função que retorna o identificador de um dado aluno
int aluno_obter_id(Aluno *);

//Função que "apaga" o aluno, liberando seu respectivo bloco de memória
void aluno_apagar(Aluno**);

#endif