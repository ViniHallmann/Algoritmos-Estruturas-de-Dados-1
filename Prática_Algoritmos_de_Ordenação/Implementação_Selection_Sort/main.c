#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM 1000

int main(){
    int vetorDesordenado [TAM], menor, aux;

    srand(time(NULL));
    for ( int i = 0; i < TAM; i++){
        vetorDesordenado [i] = rand () % 1000;
    }
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf("\n");

    clock_t inicio, fim;
    double tempoExecucao;
    inicio = clock();

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

    fim = clock();
    tempoExecucao = ( (double ) ( fim - inicio ) ) / CLOCKS_PER_SEC;
    for ( int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf( "\nTempo de execucao: %lf segundos\n", tempoExecucao );
    //COPIEI ESSE CÓDIGO PARA LIMPAR O TERMINAL
    clock_t start_time = clock();
    int desired_time = 1; 
    while ((clock() - start_time) / CLOCKS_PER_SEC < desired_time) {}
    system( "cls" );
}