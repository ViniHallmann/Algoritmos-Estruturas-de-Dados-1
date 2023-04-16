
//TRABALHO PRÁTICO 3 - VINÍCIUS HALLMANN - M1 

#include <stdio.h>
#include <stdlib.h>

struct Arvore {
    int numero;
    struct Arvore *esquerda, *direita;
}; typedef struct Arvore NoArvore;

NoArvore *InserirNumero ( NoArvore *raiz, int numeroASerInserido ){
    if ( raiz == NULL ){
        raiz = malloc ( sizeof ( NoArvore ) );
        raiz -> numero = numeroASerInserido;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else {
        if ( numeroASerInserido < raiz -> numero ){
            raiz -> esquerda = InserirNumero ( raiz -> esquerda, numeroASerInserido );
        } else {
            raiz -> direita = InserirNumero ( raiz -> direita, numeroASerInserido );
        }
        return raiz;
    }
} 

void ImprimirArvore ( NoArvore *raiz ){
    if ( raiz != NULL ){
        printf( " %d ", raiz -> numero );
        ImprimirArvore ( raiz -> esquerda );
        ImprimirArvore ( raiz -> direita );
    }
}

int CalcularAltura ( NoArvore *raiz ){
    int alturaEsquerda, alturaDireita;
    if ( raiz == NULL ){
        return 0;
    }
    // CALCULA A ALTURA DE CADA LADO DA ARVORE
    alturaEsquerda = CalcularAltura ( raiz -> esquerda ); 
    alturaDireita = CalcularAltura ( raiz -> direita );
    
    // RETORNA O VALOR DA MAIOR ALTURA
    if ( alturaEsquerda > alturaDireita ){
        return alturaEsquerda + 1;
    } else {
        return alturaDireita + 1;
    }
}

int CalcularDiametro ( NoArvore *raiz ){
    int diametroEsquerdo, diametroDireito, alturaEsquerda, alturaDireita, diametro;

    if ( raiz == NULL ){
        return 0;
    }
    alturaEsquerda = CalcularAltura ( raiz -> esquerda );
    alturaDireita = CalcularAltura ( raiz -> direita );
    diametroEsquerdo = CalcularDiametro ( raiz -> esquerda );
    diametroDireito = CalcularDiametro ( raiz -> direita );

    diametro = alturaDireita + alturaEsquerda;
    
    if ( diametroEsquerdo > diametro ) {
        diametro = diametroEsquerdo;
    } 
    if ( diametroDireito > diametro ) {
        diametro = diametroDireito;
    }

    return diametro;
}

NoArvore *LimparArvore ( NoArvore *raiz ){
    if ( raiz != NULL ){
        raiz -> esquerda = LimparArvore ( raiz -> esquerda );
        raiz -> direita = LimparArvore ( raiz -> direita );
        free ( raiz );
        return NULL;
    } else {
        return NULL;
    }
}

int main( int argc, char const *argv[] ){
    NoArvore *arvore = NULL;

    //arvore = InserirNumero ( arvore, 5);
    //arvore = InserirNumero ( arvore, 6);
    //arvore = InserirNumero ( arvore, 7); 
    //arvore = InserirNumero ( arvore, 8);
    //arvore = InserirNumero ( arvore, 9); 
    //arvore = InserirNumero ( arvore, 3);
    //arvore = InserirNumero ( arvore, 4);
    //arvore = InserirNumero ( arvore, 2);
    //arvore = InserirNumero ( arvore, 1);
    
    ImprimirArvore ( arvore );
    printf( "\nDiametro da árvore = %d ", CalcularDiametro ( arvore )); // gambiarra, funciona mas preciso arrumar isso no código depois
    arvore = LimparArvore ( arvore );
}

/*
----------------
TESTE 1
        5
      3   6
    2  4  

    SAIDA: 3
----------------
TESTE 2 
        5
      3   6
    2  4    7
              8
                9
    SAIDA: 6
----------------
TESTE 3 
        2
    1  
    SAIDA: 1
*/