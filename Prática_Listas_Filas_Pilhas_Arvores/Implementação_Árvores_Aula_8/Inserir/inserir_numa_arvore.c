#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
}NoArv;

NoArv *Inserir( NoArv *no, int num);

int main(){
    NoArv *raiz = NULL;
    raiz = Inserir ( raiz, 50);
}

NoArv *Inserir( NoArv *raiz, int num){
    if ( raiz == NULL ){
        raiz = malloc ( sizeof ( NoArv ) );
        raiz -> valor = num;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    }
    else {
        if ( num < raiz -> valor){
            raiz -> esquerda = inserir( raiz -> esquerda, num);
        } else {
            raiz -> direita = inserir ( raiz -> direita, num );
        }
        return raiz;
    }
}