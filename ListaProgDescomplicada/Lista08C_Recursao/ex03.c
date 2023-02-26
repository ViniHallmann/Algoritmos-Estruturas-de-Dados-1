/*Escreva uma funcao recursiva que calcule a soma dos primeiros n cubos: S(n) = 1^3 +2^3 + ... + n^3*/
#include <stdio.h>
#include <math.h> 

int SomaDosCubos( int n );

int main (){
    int n;
    printf( "Digite um numero N: " );
    scanf( "%d", &n );
    printf( "Somatorio dos cubos de 1 ate %d: %d", n, SomaDosCubos( n ));
}

int SomaDosCubos( int n ){
    if (n == 0)
        return 0;
    else return pow( n,3 ) + SomaDosCubos( n-1 );
}