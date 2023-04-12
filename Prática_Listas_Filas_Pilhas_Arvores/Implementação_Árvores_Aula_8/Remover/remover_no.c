#include <stdio.h>
#include <stdlib.h>

struct arvore {
    int valor;
    struct arvore *esquerda, *direita;
};typedef struct arvore NoArv;

NoArv *Inserir ( NoArv *raiz, int num ){
    if ( raiz == NULL ){
        raiz = malloc ( sizeof ( NoArv ) );
        raiz -> valor = num;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
        return raiz;
    } else {
        if ( num < raiz -> valor ){
            raiz -> esquerda = Inserir ( raiz -> esquerda, num );
        } else {
            raiz -> direita = Inserir ( raiz -> direita, num );
        }
        return raiz;
    }
}

void Imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf("%d ", raiz -> valor );
        Imprimir ( raiz -> esquerda );
        
        Imprimir ( raiz -> direita );
        
    }
}

NoArv *Remover ( NoArv *raiz, int num ){
    if ( raiz == NULL ){
        printf ("Valor não encontrado !");
        return NULL;
    } else {
        if ( raiz -> valor == num ){  // encontrou o valor na arvore
            if ( raiz -> esquerda == NULL && raiz -> direita == NULL ){ //remocam da folha sem filhos
                free ( raiz );
                return NULL;
            } // remoção com do no com os filhos
            else { // Remoção com 2 filhos
                NoArv *aux;
                if ( raiz -> esquerda != NULL && raiz -> direita != NULL ){
                    aux = raiz -> esquerda;
                    while ( aux -> direita != NULL ){
                        aux = aux -> direita;
                    }
                    raiz -> valor = aux -> valor;
                    aux -> valor = num;
                    raiz -> esquerda = Remover ( raiz -> esquerda, num);
                    return raiz;
                }
                
                else { // Remoção com 1 filho
                    NoArv *aux;
                    if ( raiz -> esquerda != NULL ){
                        aux = raiz -> esquerda; 
                    }
                    else {
                        aux = raiz -> direita;
                    }
                    free ( raiz );
                    return aux;
                }
            }
        } 
        else { // percorre a arvore procurando pelo valor a remover
            if ( num < raiz -> valor ){
                raiz -> esquerda = Remover ( raiz -> esquerda, num );
            } else {
                raiz -> direita = Remover ( raiz -> direita, num );
            }
            return raiz;
        }
    }
}
int main(){
    NoArv *arvore = NULL;
    
    arvore = Inserir ( arvore, 10);
    arvore = Inserir ( arvore, 11);
    arvore = Inserir ( arvore, 8);
    arvore = Inserir ( arvore, 7);
    arvore = Inserir ( arvore, 5);
    arvore = Inserir ( arvore, 6);
    Imprimir ( arvore );
    printf("\n");
    //arvore = Remover ( arvore, 7 );
    Imprimir ( arvore );
}