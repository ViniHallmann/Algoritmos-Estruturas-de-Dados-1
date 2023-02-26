/*Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do teclado. 
Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.
*/

#include <stdio.h>

int main(){
    int *p1, *p2;
    scanf( "%d %d", &p1, &p2 );
    if (&p1 > &p2){
        printf( "%d", &p1 );
    } else {
        printf( "%d", &p2 );
    }
        

}