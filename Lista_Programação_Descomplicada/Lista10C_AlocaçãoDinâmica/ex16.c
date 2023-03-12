/*.Faca um programa que leia dois numeros N e M: 
• Crie e leia uma matriz N x M de inteiros;
• Crie e construa uma matriz transposta M x N de inteiros.
• Mostre as duas matrizes*/
#include <stdio.h>
#include <stdlib.h>
int **CriaMatriz( int linha, int coluna, int **matriz );
void ImprimeMatriz( int linha, int coluna, int **matriz );
int **CriaTranspostaMatriz( int linha, int coluna, int **matriz, int **matrizTransposta );


int main(){

    int **matriz, linha, coluna, **novaMatriz, **novaTransposta;

    

    printf( "Digite o tamanhao da matriz N x M: " );
    scanf( "%d %d", &linha, &coluna );
    
    matriz = ( int** ) malloc( linha * sizeof ( int* ) );
    novaTransposta = ( int** ) malloc( linha * sizeof ( int* ) );

    novaMatriz = CriaMatriz( linha, coluna, matriz );
    ImprimeMatriz( linha, coluna, novaMatriz );
    novaTransposta = CriaTranspostaMatriz ( linha, coluna, novaMatriz, novaTransposta);
    ImprimeMatriz( linha, coluna, novaTransposta );

}

int **CriaMatriz( int linha, int coluna, int **matriz ){

    int l, c;

    for ( l = 0; l < linha; l++)
        matriz[l] = ( int* ) malloc ( coluna * sizeof ( int* ) );

    for ( l = 0; l < linha; l++ ){
        for ( c = 0; c < coluna; c++){
            printf( "Matriz[%d][%d]: ", l, c );
            scanf( "%d", &matriz[l][c] );
        }
    }
    return matriz;

}

void ImprimeMatriz( int linha, int coluna, int **matriz ){

    int l, c;

    printf( "\n" );

    for( l = 0; l < linha; l++ ){
        for( c = 0; c < coluna; c++ ){
            printf( " %d ", matriz[l][c] );
        }
        printf( "\n" );
    }

}

int **CriaTranspostaMatriz( int linha, int coluna, int **matriz, int **matrizTransposta ){

    int l, c;

    
    for ( l = 0; l < linha; l++)
        matrizTransposta[l] = ( int* ) malloc ( coluna * sizeof ( int* ) );

    for ( l = 0; l < linha; l++ ){
        for ( c = 0; c < coluna; c++){
            matrizTransposta[c][l] = matriz[l][c];
        }
    }
    return matrizTransposta;
    
}
