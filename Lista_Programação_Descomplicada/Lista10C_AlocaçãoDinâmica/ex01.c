/*
Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,;
(b) Peca para o usuario digitar os 5 numeros no espaco alocado;
(c) Mostre na tela os 5 numeros;
(d) Libere a memoria alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array = (int*) malloc( 5*sizeof ( int ) );
    int i;
    for ( i = 0; i < 5; i++ ){
        scanf( "%d", &array[i] ); 
    }

    for ( i = 0; i < 5; i++ ){
        printf( "array[%d] : %d\n", i, array[i] ); 
    }

    free(array);

}