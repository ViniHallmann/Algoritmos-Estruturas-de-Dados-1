#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(){
    int vetorDesordenado [TAM], menor, aux;

    srand(time(NULL));
    for ( int i = 0; i < TAM; i++){
        vetorDesordenado [i] = rand () % 100;
    }
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf("\n");
    for ( int i = 0; i < TAM; i++ ){
        menor = i;
        for ( int j = i; j < TAM; j++ ){
            if ( vetorDesordenado[menor] > vetorDesordenado[j] ){
                menor = j;
            }
        }
        aux = vetorDesordenado[menor];
        vetorDesordenado[menor] = vetorDesordenado[i];
        vetorDesordenado[i] = aux;
    }
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
}