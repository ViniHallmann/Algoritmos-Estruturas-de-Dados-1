#include <stdio.h>
int JeitosDeSubir( int n );
int main(){
    int n = 2;
    printf( "%d", JeitosDeSubir( n ) );
}

int JeitosDeSubir( int n ){
    int passoAtual = 0, passoAnterior = 1, totalPassos, i;

    if ( n <= 3 )
        return n;
    
    for( i = n; i > 0; i-- ){
        totalPassos = passoAtual + passoAnterior;
        passoAtual = passoAnterior;
        passoAnterior = totalPassos;
    }
    return totalPassos;
}