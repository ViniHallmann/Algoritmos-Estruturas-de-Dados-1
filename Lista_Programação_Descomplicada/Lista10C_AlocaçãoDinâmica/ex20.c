/*Faca um programa que:
(a) Peca para o usuario entrar com o nome e a posicao (coordenadas X e Y) de N  cidades e as armazene em um vetor de estruturas (N e informado pelo usuario);
(b) Crie uma matriz de distancias entre cidades de tamanho N x N; 
(c) Calcule as distancia entre cada duas cidades e armazene na matriz; 
(d) Exiba na tela a matriz de distancias obtida; 
(e) Quando o usuario digitar o numero de duas cidades o programa devera retornar a distancia entre elas.*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct dados{
    char name[50];
    int posX;
    int posY;
}; 
int nCities();
struct dados *InitializeVetor(int totCities);
int **CreateMatriz(int nCities);


int main(){
    struct dados *data;
    int **matriz, totCities = nCities();
    data = InitializeVetor(totCities);
    matriz = CreateMatriz(totCities);

}

int nCities(){

    int nCities;
    printf("Digite quantas cidades serão cadastradas: ");
    scanf("%d", &nCities);
    system("cls");

    return nCities;

}

struct dados *InitializeVetor( int totCities ){

    struct dados *dataVetor = ( struct dados * ) malloc( totCities * sizeof( struct dados ) );

    for ( int i = 0; i < totCities; i++){
        printf("Digite o nome da cidade: ");
        scanf("%s", dataVetor[i].name);
        getchar();

        printf("Digite a posição da cidade X Y: ");
        scanf("%d %d", &dataVetor[i].posX, &dataVetor[i].posY);
        system("cls");
    }

    for ( int i = 0; i < totCities; i++){
        printf("Nome da cidade[%d]: %s Posição X Y: %d %d\n", i, dataVetor[i].name,dataVetor[i].posX,dataVetor[i].posY);
    }
    return dataVetor;
}

int **CreateMatriz(int nCities){
    int **matriz = (int **) malloc( nCities * sizeof ( int * ) );

    for (int i = 0; i < nCities; i++){
        matriz[i] = (int *) malloc ( nCities * sizeof ( int ) );
    }

    return matriz;
}

int CalcDistance( struct dados *data, int **matriz ){

    float distance;

    //(sqrt x1 - sqrt x1)^2 - (sqrt y2 - sqrt y2)^2 
}


