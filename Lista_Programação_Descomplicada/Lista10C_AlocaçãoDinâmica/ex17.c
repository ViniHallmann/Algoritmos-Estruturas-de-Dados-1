/*Faca um programa que leia numeros do teclado e os armazene em um vetor alocado 
dinamicamente. O usuario ira digitar uma sequencia de numeros, sem limite de quantidade. Os numeros serao digitados um a um e, sendo que caso ele deseje encerrar a
entrada de dados, ele ira digitar o numero ZERO. Os dados devem ser armazenados na memoria deste modo 
• Inicie com um vetor de tamanho 10 alocado dinamicamente;
• Apos, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor anterior adicionado espaco para mais 10 valores (tamanho N+10, onde N inicia com 10);
• Copie os valores ja digitados da area inicial para esta area maior e libere a memoria da area inicial; 
• Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser expandido de 10 em 10 valores.
Ao final, exiba o vetor lido. Nao use a funcao REALLOC.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_INICIAL 10

int main (){
    int numero, *vetor, *vetorNovo, flagPosicao = 0, tamanhoNovo = TAM_INICIAL + 10, tamanhoAtual = TAM_INICIAL;
    vetor = ( int* ) malloc ( TAM_INICIAL * sizeof ( int ) );
    
    while (1){

        printf( "Digite um valor para armazenar no vetor: ");
        scanf( "%d", &numero );

        if ( numero == 0 )
            break;
        
        vetor[flagPosicao] = numero;
        flagPosicao++;

        if (flagPosicao == TAM_INICIAL){

            vetorNovo = ( int* ) malloc ( tamanhoNovo * sizeof ( int ) );

            for (int i = 0; i < tamanhoAtual; i++) {
                vetorNovo[i] = vetor[i];
            }

            free (vetor);
            vetor = vetorNovo;
            tamanhoAtual = tamanhoNovo;
            tamanhoNovo += 10;
        }

    }

    for (int i = 0; i < flagPosicao; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    free(vetor); 
}


