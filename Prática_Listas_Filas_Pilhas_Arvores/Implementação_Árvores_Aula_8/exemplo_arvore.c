#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda, *direita;
}NoArv;

NoArv* inserir(NoArv *raiz, int num){
    if (raiz == NULL){
        NoArv*aux = malloc(sizeof(NoArv));
        aux -> valor = num;
        aux -> direita = NULL;
        aux -> esquerda = NULL;
        return aux;
    }
}