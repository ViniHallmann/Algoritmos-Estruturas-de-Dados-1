#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda, *direita;
}NoArv;

void InserirSemRecursao ( NoArv **raiz, int num ){
    NoArv *aux = *raiz;
    while ( aux != NULL ){
        if ( num < aux -> valor){
            raiz = &aux -> esquerda ;
        } else {
            raiz = &aux -> direita ;
        }
        aux = *raiz; // aux recebe o conteudo da raiz, então ele continua o while caso a raiz ainda não chegou no nulo
    }
    // se o aux for nulo ele já pula direto pra essa parte do código e aloca uma raiz usando um aux.
    aux = malloc ( sizeof( NoArv ) );
    aux -> valor = num;
    aux -> esquerda = NULL;
    aux -> direita = NULL;
    *raiz = aux;  
}

void imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf("%d", raiz -> valor);
        imprimir ( raiz -> esquerda);
        imprimir ( raiz -> direita);
    }
}

int main(){
    NoArv *raiz = NULL;
    InserirSemRecursao ( &raiz, 2);
    imprimir ( &raiz );
}