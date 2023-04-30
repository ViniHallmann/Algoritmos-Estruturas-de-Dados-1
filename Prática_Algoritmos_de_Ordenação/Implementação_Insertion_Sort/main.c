#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int main(){
    int vetorDesordenado [TAM], indice, copia, i;

    srand(time(NULL));
    for ( i = 0; i < TAM; i++){
        vetorDesordenado [i] = rand () % 100;
    }
    for (  i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf("\n");
    for ( i = 1; i < TAM; i++ ){
        indice = i; 
        copia = vetorDesordenado[i];
        while ( indice > 0 && vetorDesordenado[indice - 1] > copia ){
            vetorDesordenado[indice] = vetorDesordenado [indice -1];
            indice--;
        }
        vetorDesordenado[indice] = copia;
    }
    for ( i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
}