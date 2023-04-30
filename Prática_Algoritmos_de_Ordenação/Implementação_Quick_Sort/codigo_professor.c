#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void Quicksort ( int vetorDesordenado[TAM], int esquerda, int direita );
void Imprime ( int VetorDesordenado[TAM] );

int main (){
    int vetorDesordenado [TAM] = { 3, 19, 18, 5, 13, 11, 7, 20, 0, 1 }, indice, copia, i;
    /*srand(time(NULL));
    for ( i = 0; i < TAM; i++){
        vetorDesordenado [i] = rand () % 100;
    }*/
    for (  i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
    printf("\n");
    Quicksort(vetorDesordenado, 0, TAM - 1);
    Imprime ( vetorDesordenado );
}


// 3 19 18 5 13 11 7 20 0 1 
//pivo: 13
// i = 0, j = 10;
void Quicksort ( int vetor[TAM],int esquerda, int direita ){
    int meio, temp, i, j;
    i = esquerda;
    j = direita;
    meio = vetor[(esquerda + direita)/2]; // ESCOLHA DO PIVÔ
    do {
        while ( vetor[i] < meio ) // PROCURA UM ELEMENTO MENOR QUE O PIVÔ ATÉ O MEIO
            i++; 
        while ( vetor[j] > meio) // PROCURA UM ELEMENTO MAIOR QUE O PIVÔ DO MEIO ATÉ O FIM
            j--; 
        if ( i <= j ){ // TROCA O ELEMENTO I PELO J ( SWAP )
            temp = vetor[i];        
            vetor[i] = vetor[j];    
            vetor[j] = temp;        
            i++;                    
            j--;                    
        }
        // 3 19 0 5 13 11 7 20 19 1
    } while ( i <= j );
    if ( esquerda < j )
        Quicksort ( vetor, esquerda, i);
    if ( direita > i )
        Quicksort ( vetor, i, direita);
}

void Imprime ( int vetorDesordenado[TAM] ){
    
    for (int i = 0; i < TAM; i++ ){
        printf( "%d ", vetorDesordenado[i] );
    }
}
