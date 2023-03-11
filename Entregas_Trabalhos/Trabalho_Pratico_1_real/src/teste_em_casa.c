#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VINÍCIUS HALLMANN M1

int judgeCircle( char *moves );

int main( int argc, char const *argv[] )
{
    char *moves;

    printf( "Entrada de movimentos: " );
    scanf( "%s", &moves );
    judgeCircle ( moves );

    return 0;
}

int judgeCircle( char *moves ){

    int x=0, y=0, i;
    for ( i = 0; i < strlen( moves ); i++ ){
        if ( moves[i] == 'R' )
            x += 1;
        if ( moves[i] == 'L' )
            x -= 1;
        if ( moves[i] == 'U' )
            y += 1;
        if ( moves[i] == 'D' )
            y -= 1;
    }   

    printf("%d", x);
    printf("%d", y);

    if ( x == y ){
        printf( "Verdadeiro" );
        return 1;
    } else {
        printf( "Falso" );
            return 0;
    }
        
        
}

