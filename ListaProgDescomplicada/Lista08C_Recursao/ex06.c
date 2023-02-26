/*A multiplicacao de dois numeros inteiros pode ser feita atraves de somas sucessivas. 
Proponha um algoritmo recursivo Multip Rec(n1,n2) que calcule a multiplicacao de dois inteiros.*/

#include <stdio.h>
int MultipRec( int n1, int n2 );

int main(){
    int n1, n2;
    printf( "Digite um Numero e por quanto quer multiplicar ele: " );
    scanf( "%d %d", &n1,&n2 );
    printf( "Multiplicacao de %d por %d: %d", n1,n2, MultipRec( n1,n2 ));
}

int MultipRec( int n1, int n2 ){
    if ( n1 == 0 )
        return 0;
    else n1 + MultipRec( n1, n2-1 );
}