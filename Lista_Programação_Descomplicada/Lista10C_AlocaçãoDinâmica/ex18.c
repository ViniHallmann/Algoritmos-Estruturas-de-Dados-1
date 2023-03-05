/* Escreva um programa para fazer a alocação dinamica dos blocos de dados conforme solicitado abaixo:
(a) Vetor de 1025 bytes (1kbyte)
(b) Matriz de inteiros de dimensão 10x10. V
(c) Vetor armazena 50 registros contendo: nome do produto (30 caracteres), codigo de produto(inteiro) e preco em reais (float)
(d) Texto de ate 100 linhas com ate 80 caracteres em cada linha.
*/

#include <stdio.h>
#include <stdlib.h>

int **CreateMatriz();
void PrintMatriz(int **matriz);
char CreateText();

struct dados {
    char productName[30];
    int productCode;
    float productPrice;
}; 

int main(){
    //(a)

    char *vector = (char *) malloc (1025 * sizeof (char ));
    printf("%d", sizeof(*vector));
    free(vector);

    //(b)
    int **matriz;
    matriz = CreateMatriz();
    PrintMatriz(matriz);
    for (int i = 0; i < 10; i++) {
        free(matriz[i]);
    }
    free(matriz);

    //(c)
    struct dados *vetorDeDados = ( struct dados*) malloc( 50*sizeof( struct dados ) );
    free(vetorDeDados);

    //(d)
    CreateText();
   
    
}

int **CreateMatriz(){
    int **matriz, l, c;

    matriz = (int **) malloc ( 10 * sizeof ( int *) );
    for ( int i = 0; i < 10; i++ ){
        matriz[i] = ( int *) malloc (10 * sizeof ( int * ) );
    }

    for ( l = 0; l < 10; l++){
        for ( c = 0; c < 10; c++){
            scanf( "%d", &matriz[l][c] );
        }
    }

    return matriz;
}


char CreateText(){

    char **text; 
    int i;

    text = ( char ** ) malloc ( 100 * sizeof( char *) );

    for(i = 1; i < 100; i++){
        text[i] = (char *)malloc (80 * sizeof ( char) );
    }

    for (int i = 0; i < 100; i++) {
        free(text[i]);
    }
    free(text);
}

char WriteText(){

}
void PrintMatriz(int **matriz){

    int l,c;
    for ( l = 0; l < 10; l++){
        for ( c = 0; c < 10; c++){
            printf( "%d ", matriz[l][c] );
        }
        printf("\n");
    }
}