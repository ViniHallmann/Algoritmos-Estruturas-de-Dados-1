#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VINÍCIUS HALLMANN M1

int judgeCircle( char *moves );

int main( int argc, char const *argv[] )
{
    //Mudança na inicialização do moves. No código feito em aula eu acabei esquecendo de inicializar o char *moves.
    char *moves = malloc(sizeof (moves));

    printf( "Entrada de movimentos: " );
    scanf( "%s", moves );
    judgeCircle ( moves );
    return 0;
    
}

int judgeCircle( char * moves ){

    int i, contadorR = 0, contadorL = 0, contadorD = 0, contadorU = 0;

    for ( i = 0; i < strlen( moves ); i++ ){
        if ( moves[i] == 'R' ){
            contadorR += 1;
        }
        if ( moves[i] == 'L' ){
            contadorL += 1;
        }
        if ( moves[i] == 'U' ){
            contadorU += 1;
        }    
        if ( moves[i] == 'D' ){
            contadorD += 1;
        } 
    }  
    
    // Mudança feita no if para comparar se os contadores de todas as direções estão iguais.
    if (( contadorR == contadorL) &&  (contadorD == contadorU )){
        printf( "Verdadeiro" );
        return 1;
    } else {
        printf( "Falso" );
        return 0;
    }
}

