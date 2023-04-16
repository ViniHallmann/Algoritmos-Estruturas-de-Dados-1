#include <stdio.h>
#include <stdlib.h>
struct Arvore {
    int num;
    struct Arvore *esquerda, *direita;
    short altura;
}; typedef struct Arvore NoArv;

NoArv *CriaNovoNo ( int numero ){
    NoArv *novoNo = malloc ( sizeof ( NoArv ) );
    if ( novoNo == NULL ){
        novoNo -> num = numero;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;
        novoNo -> altura = 0;
    } else {
        printf( "ERRO AO ALOCAR ESPAÇO PARA UM NOVO NÓ" );
    }
    return novoNo;
}
NoArv *Inserir ( NoArv *raiz, int numero ){
    if ( raiz == NULL ){
        raiz = malloc ( sizeof ( NoArv ) );
        raiz -> num = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else if ( numero < raiz -> num ){
        raiz -> esquerda = Inserir ( raiz -> esquerda, numero );
    } else {
        raiz -> direita = Inserir ( raiz -> direita, numero );
    }
    return raiz;
}

void Imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf ( " %d ", raiz -> num );
        Imprimir ( raiz -> esquerda );
        Imprimir ( raiz -> direita );
    }
}

int altura ( NoArv *raiz ){
    if ( raiz == NULL )
        return -1;
    int alturaEsquerda = 1 + altura ( raiz -> esquerda );
    int alturaDireita = 1 + altura ( raiz -> direita );
    if ( alturaEsquerda > alturaDireita )
        return alturaEsquerda;
    else {
        return alturaDireita;
    }
}
short AlturaDoNo ( NoArv *raiz ){
    if ( raiz == NULL)
        return -1;
    else 
        return raiz -> altura;
}
short MaiorAltura ( short primeiraAltura, short segundaAltura ){
    if ( primeiraAltura > segundaAltura )
        return primeiraAltura;
    else 
        return segundaAltura;
}

int calculoFB ( NoArv *raiz ){
    if ( raiz == NULL )
        return 0;
    return altura( raiz -> esquerda ) - altura ( raiz -> direita );
}

NoArv *RotacaoEsquerda ( NoArv *raiz ){
    NoArv *nodoDireita, *nodoDireitaEsquerda;

    nodoDireita = raiz -> direita;
    nodoDireitaEsquerda = nodoDireita -> esquerda;

    nodoDireita -> esquerda = raiz;
    raiz -> direita = nodoDireitaEsquerda;

    return nodoDireita;
}
int main (){
    NoArv *arvore = NULL;
    arvore = Inserir ( arvore, 2);
    arvore = Inserir ( arvore, 3);
    arvore = Inserir ( arvore, 4);
    Imprimir ( arvore );
    printf("\n");
    arvore = RotacaoEsquerda ( arvore );
    Imprimir ( arvore );
}