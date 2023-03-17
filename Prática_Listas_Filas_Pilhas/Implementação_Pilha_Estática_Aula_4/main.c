#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 10

struct Aluno{
    int ra;
    char nome[50];
}; typedef struct Aluno aluno;

struct Pilha {
    struct Aluno alunos[TAM];
    int top;
    int base;
    int limit;
    
};

void reset( struct Pilha *pilha );
bool empty( struct Pilha *pilha);
bool full( struct Pilha *pilha);
bool push ( struct Pilha *pilha, struct Aluno *item );
void pop (struct Pilha *pilha, struct Aluno *aluno);
void list (struct Pilha *pilha);

int main(){
    struct Pilha pilha;
    reset(&pilha);

    struct Aluno aluno1 = {123, "Joao"};
    push(&pilha, &aluno1);

    struct Aluno aluno2 = {321, "Maria"};
    push(&pilha, &aluno2);

    list (&pilha);
}

void reset( struct Pilha *pilha ){
    pilha -> top = 0;
    pilha -> base = 0;
    pilha -> limit = TAM;
}

bool empty( struct Pilha *pilha){
    return pilha -> top == 0;
}

bool full( struct Pilha *pilha){
    return pilha-> top == TAM;
}

bool push ( struct Pilha *pilha, struct Aluno *item ){
    if (!full(pilha)){
        pilha -> alunos[pilha -> top] = *item;
        pilha -> top++;
        return true;
    } else {
        return false;
    }
}

void pop (struct Pilha *pilha, struct Aluno *aluno){

    if (pilha -> top == 0){
        return;
    } else {
        pilha -> top--;
        *aluno = pilha -> alunos[ pilha -> top];
    }
        
    
}

void list (struct Pilha *pilha) {
    while (!empty(pilha)){
        struct Aluno aluno;
        pop(pilha, &aluno);
        printf("\n%d - %s", aluno.ra, aluno.nome);
    }
}