/*Faca um programa que entao leia uma string e a imprima.*/

#define TAM 100
#include <stdio.h>
#include <string.h>

int main(){
    int i, tamanho = 0; char s[ TAM ], s2[ TAM ], c;

    printf( "Digite uma string: " );

    while ( ( c = getchar() ) && c != '\n' ){
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    for ( i = 0; i <= strlen(s); i++ ){
        printf( "%c", s[i] );
    }
    printf( "\n" );
    printf( "Digite uma string de novo: " );
    gets( s );
    tamanho = strlen( s2 );

    for ( i = 0; i <= tamanho; i++ ){
        printf( "%c", s[i] );
    }
}