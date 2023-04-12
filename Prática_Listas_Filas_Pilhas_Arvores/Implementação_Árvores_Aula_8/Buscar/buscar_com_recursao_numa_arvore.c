#include <stdio.h>
#include <stdlib.h>

struct Arvore {
    int valor;
    struct Arvore *esquerda, *direita;
}; typedef struct Arvore NoArv;

void *Inserir( NoArv *raiz, int num ){
    if ( raiz == NULL){
        raiz = malloc ( sizeof ( NoArv ) );
        raiz -> valor = num;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else {
        if ( num < raiz -> valor ){
            raiz -> esquerda = Inserir ( raiz -> esquerda, num );
        } else {
            raiz -> direita = Inserir ( raiz -> direita, num);
        }
        return raiz;
    }
    
}
int BuscaRetornandoTrueOuFalse ( NoArv *raiz, int num ){
    int temp;
    if ( raiz == NULL){
        return 0;
    }
    if ( raiz -> valor == num){
        return 1;
    } 
    if ( num < raiz -> valor ){
        temp = BuscaRetornandoTrueOuFalse ( raiz -> esquerda, num);
        return temp;
    } else {
        temp = BuscaRetornandoTrueOuFalse ( raiz -> direita, num);
        return temp;
    }
}

NoArv *BuscaRetornandoNo ( NoArv *raiz, int num ){
    NoArv *temp;
    if ( raiz != NULL ){
        if ( num == raiz -> valor){
            return raiz;
        } else if ( num < raiz -> valor ){
            temp = BuscaRetornandoNo ( raiz -> esquerda, num );
            return temp;
        } else {
            temp = BuscaRetornandoNo ( raiz -> direita, num );
            return temp;
        }
    }
    // Se o numero não estiver na arvore 
    return NULL;
}
void Imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf( "%d ", raiz -> valor ); // imprime a raiz
        Imprimir ( raiz -> esquerda ); // imprime todos da esquerda primeiro
        Imprimir ( raiz -> direita ); // Depois imprime todos da direita
    }
}
/*Primeira inserção
      10
            20
Segunda inserção
        10
    1       20
Terceira inserção
         10
    1         20
        9
Quarta inserção 
         10
    1          20
       9   15
*/


int main(){
    NoArv *raiz = NULL, *aux;        
    raiz = Inserir ( raiz, 10 );
    raiz = Inserir ( raiz, 20 );
    raiz = Inserir ( raiz, 1 );
    raiz = Inserir ( raiz, 9 );
    raiz = Inserir ( raiz, 19 );
    raiz = Inserir ( raiz, 16 );
    raiz = Inserir ( raiz, 17 );
    raiz = Inserir ( raiz, 15 );
    Imprimir ( raiz );
    int busca = BuscaRetornandoTrueOuFalse ( raiz, 16 );
    if ( busca == 1 ){
        printf( "\nValor encontrado na árvore!! " );
    } else {
        printf( "\nValor não encontrado na árvore... " );
    }
    aux = BuscaRetornandoNo ( raiz, 20 );
    // Imprime o valor encontrado
    printf ("\n%d\n", aux -> valor);
    // Imprime o valor encontrado e seus filhos
    printf("\n");
    Imprimir ( aux );
}   