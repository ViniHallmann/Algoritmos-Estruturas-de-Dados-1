/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificacao*/
#include <stdio.h>
int main (){
    int *pj, j = 1; 
    char *pi, i = 'a';
    printf("%d %c", j, i);

    pi = &i;
    pj = &j;

    printf("\n%d %c", *pj, *pi);

}