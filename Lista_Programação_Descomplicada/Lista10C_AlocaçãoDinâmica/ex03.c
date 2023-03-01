/*Faca um programa que receba do usuario o tamanho de uma string e chame uma 
funcao para alocar dinamicamente essa string. Em seguida, o usuario devera informar o 
conteudo dessa string. O programa imprime a string sem suas vogais. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *FuncaoAloc( int tamanhoString );
void LerString( int tamanhoString );

int main(){
    int tamanhoString;
    printf( "Digite o tamanho de uma string: ");
    scanf( "%d", &tamanhoString );
    getchar();
    FuncaoAloc ( tamanhoString );
    LerString ( tamanhoString );
}

char *FuncaoAloc( int tamanhoString ){
    char *string = (char *) malloc( sizeof (tamanhoString) + 1) ;
    return string;
}

void LerString( int tamanhoString ){
    char c, string[ tamanhoString ], stringAux[tamanhoString], vogais[5] = {'a','e','i','o','u'};

    int i = 0, flagVogal = 0, j, auxTamanho = tamanhoString;
    printf( "Digite uma string: " );
    while ((c = getchar()) && tamanhoString >= 0 && c != '\n'){
        string[i] = c;
        i++;
        tamanhoString--;
    }
    string[i] = '\0';


    for ( i = 0; i <= auxTamanho; i++){
        flagVogal = 0;
        for( j = 1; j < 5; j++ ){
            if(string[i] == vogais[j]){
                flagVogal = 1;
                break; // no momento que encontrar uma vogal nao tem pq continuar verificando
            }
        } 
        if (flagVogal == 0)
            stringAux[i] = string[i];
    }
    stringAux[i] = '\0';
    printf("%s", stringAux);
}