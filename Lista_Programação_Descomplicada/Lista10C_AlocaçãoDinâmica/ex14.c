/*Construa um programa que leia o numero de linhas e de colunas de uma matriz de numeros reais, aloque espaco dinamicamente para esta e a inicialize com valores fornecidos pelo usuario.
Ao final, o programa devera retornar a matriz na saıda padrao com layout apropriado.*/

#include <stdio.h>
#include <stdlib.h>

int main (){

    float **matriz;
    int linha, coluna, l, c;

    printf( "Digite o tamanho da matriz: ");
    scanf( "%d %d", &linha, &coluna);

    matriz = ( float** ) malloc( linha * sizeof( float* ) );
    for (l = 0; l < linha; l++){
        matriz[l] = ( float* ) malloc( coluna * sizeof( float *) );
    }

    for ( l = 0; l < linha; l++ ){
        for ( c = 0; c < coluna; c++){
            printf( "Matriz[%d][%d]: ", l,c );
            scanf( "%f", &matriz[l][c] );
        }
    }

    printf("\n  Matriz\n");

    for( l = 0; l < linha; l++ ){
        for( c = 0; c < coluna; c++ ){
            printf( " %.1f ", matriz[l][c] );
        }
        printf("\n");
    }

}