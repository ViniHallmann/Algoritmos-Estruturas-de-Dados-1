#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Aluno {
    int mat;
    char name[50];
}; typedef struct Aluno aluno;

struct Pilha {
    aluno *alunos;
    aluno *top;
    aluno *base;
    int limit;
}; typedef struct Pilha pilha;

void reset (pilha *pilha){
    pilha -> alunos = NULL;
    pilha -> top = NULL;
    pilha -> base = NULL;
    pilha -> limit = 0;
}

bool empty( pilha *pilha ){
    return pilha -> top == NULL;
}

bool full ( pilha *pilha ){
    return false;
}

bool push ( pilha *pilha, aluno *item ){
    aluno *alunos;

    pilha -> limit++;
    alunos = (aluno *)malloc (sizeof(aluno)*pilha->limit);

    memcpy(alunos, pilha -> alunos, pilha -> limit - 1);
}