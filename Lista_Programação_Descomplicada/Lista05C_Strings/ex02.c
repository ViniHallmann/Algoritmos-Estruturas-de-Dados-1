/*Crie um programa que calcula o comprimento de uma string (nao use a funcao strlen).*/
#include <stdio.h>
#define TAM 100
int main(){
    char s[TAM], c;
    int i, contador = 0;
    printf( "Digite um string: " );

    while ( ( c = getchar() ) && c != '\n' ){
        s[i] = c;
        i++;
        contador++;
    }
    printf( "Comprimento da String: %d", contador );
}