#include <stdio.h>
#include <stdlib.h>

struct Arvore{
    int valor;
    struct Arvore *esquerda, *direita;
}; typedef struct Arvore NoArv;

NoArv *InserirNaArvore ( NoArv *raiz, int num );
void ImprimirArvore ( NoArv *raiz );
void ImprimirArvoreOrdenada ( NoArv *raiz );
int main(){
    NoArv *raiz = NULL;
    int escolha, valor;
    do {
        printf( "\n\t(0) - Sair \n\t(1)Inserir na árvore \n\t(2)Imprimir na árvore\n" );
        printf( "\n\tDigite uma opção: ");
        scanf ( "%d", &escolha );
        switch ( escolha )
        {
        case 1:
            printf ( "\n\tDigite um valor: ");
            scanf ( "%d", &valor );
            raiz = InserirNaArvore ( raiz, valor );
            break;
        case 2:
            ImprimirArvore ( raiz );
            break;
        
        default:
            break;
        }
    } while ( escolha != 0);
}

NoArv *InserirNaArvore ( NoArv *raiz, int num ){
    if ( raiz == NULL ){
        NoArv *no = malloc ( sizeof ( NoArv ) );
        no -> valor = num;
        no -> esquerda = NULL;
        no -> direita = NULL;
        return no;
    } else {
        if ( num == raiz -> valor ){
            return raiz;
        }
        if ( num < raiz -> valor ){
            raiz -> esquerda = InserirNaArvore ( raiz -> esquerda, num );
        } else {
            raiz -> direita = InserirNaArvore ( raiz -> direita, num);
        } 
        return raiz;
    }
    
}

void ImprimirArvore ( NoArv *raiz ){
    if ( raiz != NULL ) {
        printf (" %d ", raiz -> valor );
        ImprimirArvore ( raiz -> esquerda);
        ImprimirArvore ( raiz -> direita);
    } 
}

void ImprimirArvoreOrdenada ( NoArv *raiz ){
    if ( raiz != NULL  ){
        ImprimirArvoreOrdenada ( raiz -> esquerda);
        printf (" %d ", raiz -> valor );
        ImprimirArvoreOrdenada ( raiz -> direita);
    }
}
