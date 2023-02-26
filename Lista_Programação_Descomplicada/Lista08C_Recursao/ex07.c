/*Faca uma funcao recursiva que receba um numero inteiro positivo N e imprima todos os numeros naturais de 0 ate N em ordem crescente*/
#include <stdio.h>

int NumerosNaturais( int n );

int main (){
    int n;
    printf("Digite um numero N: ");
    scanf( "%d", &n );
    NumerosNaturais( n );
}

int NumerosNaturais( int n ){
    
    if (n == 0)
        printf( "%d ", n ); 
    else {
        NumerosNaturais( n-1 );
        printf( "%d ", n );
    }
}