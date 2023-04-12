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
NoArv *BuscaSemRecusao ( NoArv *raiz, int num ){
    //NoArv *aux = raiz;
    while ( raiz != NULL ){
        if ( num < raiz -> valor ){
            raiz = raiz -> esquerda;
        } else if ( num > raiz -> valor ){
            raiz = raiz -> direita;
        } else {
            printf("\nNumero encontrado na árvore %d", *raiz);
            return raiz;
        }
    }
    // cai nesse retorno se a arvore for nula ou se o num não existir na arvore
    return NULL;
}
void imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf(" %d ", raiz -> valor);
        imprimir ( raiz -> esquerda);
        imprimir ( raiz -> direita);
    }
}

int main(){
    NoArv *raiz = NULL, *busca;
    InserirSemRecursao ( &raiz, 20);
    InserirSemRecursao ( &raiz, 10);
    InserirSemRecursao ( &raiz, 25);
    InserirSemRecursao ( &raiz, 15);
    InserirSemRecursao ( &raiz, 30);
    InserirSemRecursao ( &raiz, 5);
    imprimir ( raiz );
    busca = BuscaSemRecusao ( raiz, 10 );
    printf ("\n%d", busca -> valor);
    
}