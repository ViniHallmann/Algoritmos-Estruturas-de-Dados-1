#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define TAM 5

int vector[TAM];

void createVector (){
    srand ( time ( NULL ) );
    for ( int i = 0; i < TAM; i++ ){
        vector[i] = rand () % 100;
    }
}

void printVector ( int printThisVector[TAM] ){
    for ( int i = 0; i < TAM; i++){
        printf( "%d ", vector[i]);
    }
    printf( "\n" );
}
int *copyVector ( int vector[TAM] ){
    int *copy = malloc ( TAM * sizeof ( int ) );
    for ( int i = 0; i < TAM; i++){
        copy[i] = vector[i];
    }
    return copy;
}
/*int *selectionSort( int sortThisVector[TAM] ){
    int i, j, smallerNumber, *vector = malloc ( TAM * sizeof ( int ) ), aux;
    vector = copyVector ( sortThisVector );
    for ( i = 0; i < TAM; i++ ){
        smallerNumber = i;
        for ( j = i; j < TAM - 1; j++ ){
            if ( vector[smallerNumber] > vector [j] )
                smallerNumber = j;
        }
        aux = vector[smallerNumber];
        vector[smallerNumber] = vector[i];
        vector[i] = aux;
    }
    return vector;
}*/
void selectionSort( int vector[TAM] ){
    int i, j, smallerNumber, aux;

    for ( i = 0; i < TAM; i++ ){
        smallerNumber = i;
        for ( j = i; j < TAM ; j++ ){
            if ( vector[smallerNumber] > vector [j] )
                smallerNumber = j;
        }
        aux = vector[smallerNumber];
        vector[smallerNumber] = vector[i];
        vector[i] = aux;
    }
}

void insertionSort ( int vector[TAM] ){
    int i, indice, copia;
    for ( i = 1; i < TAM; i++ ){
        indice = i;
        copia = vector[i];
        while ( indice > 0 && vector [ indice - 1] > copia ){
            vector[indice] = vector[indice - 1];
            indice--;
        }
        vector[indice] = copia;
    }
}
int main (){
    createVector();
    printVector( vector );
    insertionSort( vector );
    printVector( vector );
}