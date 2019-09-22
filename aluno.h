#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

//Funcao que cria o ponteiro do TAD aluno e retorna-o para referencia
Aluno *aluno_criar(int identificador, float horas_estudo, float nota1, float nota2);

//Funcao que permite a atualização das horas de estudo de um aluno
void aluno_atualizar_horas(Aluno*, int horas);
int aluno_obter_horas(Aluno*);

//Funcao que permite atualiza a nota 1 do aluno
void aluno_atualizar_nota1(Aluno*, int nota1);
int aluno_obter_nota1(Aluno*);

//Funcao que permite atualizar a nota 2 do aluno
void aluno_atualizar_nota2(Aluno*, int nota2);
int aluno_obter_nota2(Aluno*);

//Funcao que retorna o proximo aluno da lista, mantendo o objetivo de se usar um TAD (information hiding)
Aluno *aluno_obter_proximo(Aluno*);
void aluno_definir_proximo(Aluno*, Aluno*);

//Funcao que retorna o identificador de um dado aluno
int aluno_obter_id(Aluno *);

//Funcao que "apaga" o aluno, liberando seu respectivo bloco de memória
void aluno_apagar(Aluno**);

#endif