/*Crie uma funcao recursiva que receba um numero inteiro positivo N e calcule o somatorio dos numeros de 1 a N.*/

#include <stdio.h>
int Soma( int n );

int main(){
    int n;
    printf( "Digite um numero N: " );
    scanf( "%d", &n );

    printf( "De 1 ate %d: %d", n,  Soma( n ) );
}

int Soma( int n ){
    if (n == 0)
        return 0;
    else return n + Soma(n-1);
}