#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL 10

int main(){
    int *vetor, numero, posicao = 0, tamAtual = TAM_INICIAL;
    vetor = ( int* ) malloc ( TAM_INICIAL * sizeof ( int ) );

    while(1){

        printf("Digite um numero: ");
        scanf("%d", &numero);

        
        if (numero == 0){
            break;
        }
            
        vetor[posicao] = numero;
        posicao++;

        if (posicao == tamAtual){
            vetor = (int *) realloc(vetor, tamAtual + 10);
        }
        tamAtual += TAM_INICIAL;

    }

    for (int i = 0; i < posicao; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    free(vetor); 
}