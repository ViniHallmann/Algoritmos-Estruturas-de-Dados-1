/*Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereco de cada posicao desse array*/

#include <stdio.h>

int main(){
    int array[10], i;

    for( i = 0; i <= 10; i++){
        array[i] = i;
    }

    for( i = 0; i <= 10; i++){
        printf( " %d ", array[i]);
    }

    printf("\n");
    
    for( i = 0; i <= 10; i++){
        printf( " %d ", &array[i]);
    }

}