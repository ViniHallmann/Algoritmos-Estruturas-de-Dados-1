#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int valor;
    struct arvore *esquerda, *direita;
};typedef struct arvore NoArv;

NoArv *Inserir ( NoArv *raiz, int num ){
    if ( raiz == NULL ){
        raiz = malloc ( sizeof ( NoArv ) );
        raiz -> valor = num;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else {
        if ( num < raiz -> valor ){
            raiz -> esquerda = Inserir ( raiz -> esquerda, num );
        } else {
            raiz -> direita = Inserir ( raiz -> direita, num );
        }
        return raiz;
    }
}

void Imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf("%d ", raiz -> valor );
        Imprimir ( raiz -> esquerda );
        Imprimir ( raiz -> direita );
    }
}

int QtdFolhas ( NoArv *raiz){
    if ( raiz == NULL ){
        return 0;
    } else if ( raiz -> esquerda == NULL && raiz -> direita == NULL ){
        return 1;
    } else {
        int qtdFolhasEsquerda = QtdFolhas ( raiz -> esquerda ), qtdFolhasDireita = QtdFolhas ( raiz -> direita );
        return qtdFolhasEsquerda + qtdFolhasDireita;
    }
        
}

int main(){
    NoArv *arvore = NULL;
    int i, num = 10;
    for ( int i; i < 5; i ++){
        arvore = Inserir ( arvore, num );
        num += 10;
    }
    //Imprimir ( arvore );
    printf ("%d", QtdFolhas(arvore));
}