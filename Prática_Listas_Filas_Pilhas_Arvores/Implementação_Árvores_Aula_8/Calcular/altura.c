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
int CalculoAltura ( NoArv *raiz ){
    if ( raiz == NULL ){
        return -1; // isso aqui é pra caso a arvore só tenha raiz, o calculo da altura vai retornar 1, mas o tamanho correto é 0
    } else {
        int alturaEsquerda = CalculoAltura ( raiz -> esquerda ), alturaDireita = CalculoAltura ( raiz -> direita );
        if ( alturaEsquerda > alturaDireita ){
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}
void Imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf("%d ", raiz -> valor );
        Imprimir ( raiz -> esquerda );
        Imprimir ( raiz -> direita );
    }
}

int main(){
    NoArv *arvore = NULL;
    int i, num = 10;
    for ( int i; i < 9; i ++){
        arvore = Inserir ( arvore, num );
        num += 10;
    }
    Imprimir ( arvore );
    printf("%d", CalculoAltura ( arvore ));
}