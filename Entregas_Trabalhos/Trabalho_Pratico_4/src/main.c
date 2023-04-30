//VINÍCIUS HALLMANN - M1 
#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int vetorExemplo1 [] = {2,1,3,3};
int kExemplo1 = 2;

int vetorExemplo2 [] = {-1, -2, 3, 4};
int kExemplo2 = 3;

int vetorExemplo3 [] = {3, 4, 3, 3};
int kExemplo3 = 2;

void ordenarVetor       ( int vetorASerOrdenado[] );
void ordenarMatriz      ( int vetorASerOrdenado[], int k );
void ImprimeVetor       ( int vetorASerImprimido[] );
int *calcularMaiorSoma  ( int vetor[], int k );
void ImprimeMatriz      ( int vetorASerImprimido[], int k );

int main(int argc, char const *argv[])
{
    printf( "\nVetores desordenados: \n");
    ImprimeVetor ( vetorExemplo1 );
    ImprimeVetor ( vetorExemplo2 );
    ImprimeVetor ( vetorExemplo3 );

    ordenarVetor ( vetorExemplo1 );
    ordenarVetor ( vetorExemplo2 );
    ordenarVetor ( vetorExemplo3 );

    printf( "\nVetores ordenados: \n");
    ImprimeVetor ( vetorExemplo1 );
    ImprimeVetor ( vetorExemplo2 );
    ImprimeVetor ( vetorExemplo3 );

    printf( "\nMatriz da subsequência: \n");

    int *matrizVetorExemplo1 = calcularMaiorSoma ( vetorExemplo1, kExemplo1 );
    ImprimeMatriz ( matrizVetorExemplo1, kExemplo1 );
    int *matrizVetorExemplo2 = calcularMaiorSoma ( vetorExemplo2, kExemplo2 );
    ImprimeMatriz ( matrizVetorExemplo2, kExemplo2 );
    int *matrizVetorExemplo3 = calcularMaiorSoma ( vetorExemplo3, kExemplo3 );
    ImprimeMatriz ( matrizVetorExemplo3, kExemplo3 );

}

void ordenarVetor ( int vetorASerOrdenado[] ){
    int i, menorNumero, j, aux;

    for ( i = 0; i < TAM; i++ ){
        menorNumero = i;
        for ( j = i; j < TAM; j++ ){
            if ( vetorASerOrdenado[menorNumero] > vetorASerOrdenado[j]){
                menorNumero = j;
            }
        }
        aux = vetorASerOrdenado[menorNumero];
        vetorASerOrdenado[menorNumero] = vetorASerOrdenado[i];
        vetorASerOrdenado[i] = aux;
    }
}

void ordenarMatriz ( int vetorASerOrdenado[], int k ){
    int i, menorNumero, j, aux;

    for ( i = 0; i < k; i++ ){
        menorNumero = i;
        for ( j = i; j < k; j++ ){
            if ( vetorASerOrdenado[menorNumero] > vetorASerOrdenado[j]){
                menorNumero = j;
            }
        }
        aux = vetorASerOrdenado[menorNumero];
        vetorASerOrdenado[menorNumero] = vetorASerOrdenado[i];
        vetorASerOrdenado[i] = aux;
    }
}

void ImprimeVetor( int vetorASerImprimido[] ){
    for ( int i = 0; i < 4; i++ ){
        printf ( " %d ", vetorASerImprimido[i] );
    }
    printf( "\n" );
}

void ImprimeMatriz( int vetorASerImprimido[], int k ){
    for ( int i = 0; i < k; i++ ){
        printf ( " %d ", vetorASerImprimido[i] );
    }
    printf( "\n" );
}

int *calcularMaiorSoma( int vetor[], int k ){
    int i, tamanhoVetor = TAM, *matriz = malloc ( k * sizeof ( int ) );

    for ( i = 0; i < TAM; i++){
        matriz[i] = vetor[tamanhoVetor - 1];
        tamanhoVetor--;
    }
    ordenarMatriz ( matriz, k );
    return matriz;
}

