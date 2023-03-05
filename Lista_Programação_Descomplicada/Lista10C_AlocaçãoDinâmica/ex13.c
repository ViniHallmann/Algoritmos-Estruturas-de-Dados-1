/*Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes definidas pelo usuario e a leia. Em seguida, implemente uma funcao que receba um 
valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz.*/

#include <stdio.h>
#include <stdlib.h>
int TemNaMatriz( int valor, int** matriz, int linha, int coluna );

int main (){

    int l, c, **matriz, linha, coluna, valor;

    printf( "Digite o tamanho da matriz: ");
    scanf( "%d %d", &linha, &coluna);
    
    /*Quando você usa ponteiros para alocar memória dinamicamente, é necessário usar um ponteiro para armazenar o endereço base do bloco de memória alocado e um ponteiro para indexar os elementos da matriz. 
    Portanto, você precisa de um ponteiro para o primeiro elemento da matriz (o ponteiro base) e um ponteiro para acessar o elemento desejado. Esses dois ponteiros formam o ponteiro duplo.*/

    matriz = ( int** ) malloc( linha * sizeof( int *) );
    for ( l = 0; l < linha; l++){
        matriz[l] = ( int* ) malloc( coluna * sizeof( int *) );
    }

    for( l = 0; l < linha; l++ ){
        for( c = 0; c < coluna; c++ ){
            printf( "Matriz[%d][%d]: ", l,c );
            scanf( "%d", &matriz[l][c] );
        }
    }

    printf("\n  Matriz\n");

    for( l = 0; l < linha; l++ ){
        for( c = 0; c < coluna; c++ ){
            printf( "%d ", matriz[l][c] );
        }
        printf("\n");
    }
    
    printf( "\nDigite um valor N: " );
    scanf( "%d", &valor );

    printf( "%d", TemNaMatriz ( valor, matriz, linha, coluna ) );

    for (l = 0; l < linha; l++) {
        free(matriz[l]);
    }
    free(matriz);

}

int TemNaMatriz( int valor, int** matriz, int linha, int coluna ){
    
    int l, c;

    for( l = 0; l < linha; l++ ){
        for( c = 0; c < coluna; c++ ){
            if ( matriz[l][c] == valor ){
                return 1;
            }
        }
    }
    return 0;
}
