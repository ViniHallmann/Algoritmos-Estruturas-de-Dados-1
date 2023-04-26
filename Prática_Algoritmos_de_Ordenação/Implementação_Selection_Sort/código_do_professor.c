#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(){
    int vetorDesordenado [TAM], menor, menor_id, aux;

    srand(time(NULL));
    for ( int i = 0; i < TAM; i++){
        vetorDesordenado [i] = rand () % 100;
    }
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf("\n");
    for ( int i = 0; i < TAM -1; i++ ){
        menor = vetorDesordenado[i];
        for ( int j = i + 1; j < TAM; j++ ){
            if ( vetorDesordenado[j] < menor ){
                menor = vetorDesordenado[j];
                menor_id = j;
            }
        }
        aux = vetorDesordenado[i];
        vetorDesordenado[i] = vetorDesordenado[menor_id];
        vetorDesordenado[menor_id] = aux;
        menor_id = i+1;
    }
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
}