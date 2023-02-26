/*Faca uma funcao recursiva que receba um numero inteiro positivo N e imprima todos os numeros naturais de 0 ate N em ordem decrescente*/
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
        printf("%d",n); 
    else {
        printf("%d ", n);
        NumerosNaturais(n-1);
    }
        
}