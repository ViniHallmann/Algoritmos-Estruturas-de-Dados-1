/*Escreva uma funcao que dado um numero real passado como parametro, retorne a parte
inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao.
Prototipo: void frac(float num, int* inteiro, float* frac);*/

#include <stdio.h>
void funcao(float numero, int* inteiro, float* frac);

int main(){
    int inteiro;
    float numero, fracao;
    printf( "Digite um numero real: " );
    scanf( "%f", &numero );
    funcao( numero, &inteiro, &fracao );

    printf("Parte inteira: %d\n", inteiro);
    printf("Parte fracionaria: %.01f", fracao);

}

void funcao(float numero, int* inteiro, float* fracao){

    *inteiro = ((int )numero);
    *fracao = numero - *inteiro;
}