/*Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao
dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o vetor lido.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanhoVetor, i, *vetor;
    printf( "Digite o tamanho do vetor: " );
    scanf( "%d", &tamanhoVetor);

    vetor = ( int* ) malloc( tamanhoVetor * ( sizeof ( int ) ) );

    for ( i = 0; i < tamanhoVetor; i++){
        scanf( "%d", &vetor[i] );
    }

    for ( i = 0; i < tamanhoVetor; i++){
        printf( "Vetor[%d]: %d\n", i+1, vetor[i] );
    }

}