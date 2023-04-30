//VINÍCIUS HALLMANN - M1 
#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void OrdenarVetor               ( int vetorASerOrdenado[], int tamanhoVetor );
void ImprimeVetor               ( int vetorASerImprimido[], int tamanhoVetor );
int *CalcularMaiorSubsequencia  ( int vetor[], int k );

int main(int argc, char const *argv[])
{
    int vetorExemplo1 [] = {2,1,3,3};
    int kExemplo1 = 2;

    int vetorExemplo2 [] = {-1, -2, 3, 4};
    int kExemplo2 = 3;

    int vetorExemplo3 [] = {3, 4, 3, 3};
    int kExemplo3 = 2;

    printf( "\nVetores desordenados: \n");
    ImprimeVetor ( vetorExemplo1, 4 );
    ImprimeVetor ( vetorExemplo2, 4 );
    ImprimeVetor ( vetorExemplo3, 4 );

    OrdenarVetor ( vetorExemplo1, 4 );
    OrdenarVetor ( vetorExemplo2, 4 );
    OrdenarVetor ( vetorExemplo3, 4 );

    printf( "\nVetores ordenados: \n");
    ImprimeVetor ( vetorExemplo1, 4)  ;
    ImprimeVetor ( vetorExemplo2, 4 );
    ImprimeVetor ( vetorExemplo3, 4 );

    printf( "\nMatriz da subsequência: \n");

    int *matrizVetorExemplo1 = CalcularMaiorSubsequencia ( vetorExemplo1, kExemplo1 );
    int *matrizVetorExemplo2 = CalcularMaiorSubsequencia ( vetorExemplo2, kExemplo2 );
    int *matrizVetorExemplo3 = CalcularMaiorSubsequencia ( vetorExemplo3, kExemplo3 );

    ImprimeVetor ( matrizVetorExemplo1, kExemplo1 );
    ImprimeVetor ( matrizVetorExemplo2, kExemplo2 );
    ImprimeVetor ( matrizVetorExemplo3, kExemplo3 );

    free( matrizVetorExemplo1 );
    free( matrizVetorExemplo2 );
    free( matrizVetorExemplo3 );
}

void OrdenarVetor ( int vetorASerOrdenado[], int tamanhoVetor ){
    int i, menorNumero, j, aux;

    for ( i = 0; i < tamanhoVetor; i++ ){
        menorNumero = i;
        for ( j = i; j < tamanhoVetor; j++ ){
            if ( vetorASerOrdenado[menorNumero] > vetorASerOrdenado[j]){
                menorNumero = j;
            }
        }
        aux = vetorASerOrdenado[menorNumero];
        vetorASerOrdenado[menorNumero] = vetorASerOrdenado[i];
        vetorASerOrdenado[i] = aux;
    }
}

void ImprimeVetor( int vetorASerImprimido[], int tamanhoVetor ){
    for ( int i = 0; i < tamanhoVetor; i++ ){
        printf ( " %d ", vetorASerImprimido[i] );
    }
    printf( "\n" );
}

int *CalcularMaiorSubsequencia( int vetor[], int k ){
    int i, tamanhoVetor = TAM, *matriz = malloc ( k * sizeof ( int ) );

    for ( i = 0; i < k; i++){
        matriz[i] = vetor[tamanhoVetor - 1];
        tamanhoVetor--;
    }
    OrdenarVetor ( matriz, k );
    return matriz;
}


