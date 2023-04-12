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

int NosExistentes ( NoArv *raiz){
    if ( raiz == NULL ){
        return 0;
    } else {
        int qtdNosEsquerda = NosExistentes ( raiz -> esquerda ), qtdNosDireita = NosExistentes( raiz -> direita ); 
        return qtdNosEsquerda + qtdNosDireita + 1;
    }
}

int QtdNos ( NoArv *raiz ){
    if ( raiz == NULL ){
        return 0;
    } else {
        return 1 + QtdNos ( raiz -> esquerda ) + QtdNos ( raiz -> direita );
    }
}
int main(){
    NoArv *arvore = NULL;
    int i, num = 10;
    for ( int i; i < 10; i ++){
        arvore = Inserir ( arvore, num );
        num += 10;
    }
    //Imprimir ( arvore );
    printf ("%d", NosExistentes(arvore));
}