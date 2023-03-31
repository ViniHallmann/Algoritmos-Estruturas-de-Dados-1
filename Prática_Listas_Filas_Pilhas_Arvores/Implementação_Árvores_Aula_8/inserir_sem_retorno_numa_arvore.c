#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerda, *direita;
}NoArv;

void inserirSemRetorno (NoArv **raiz, int num){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(NoArv));
        (*raiz) -> valor = num;
        (*raiz) -> direita = NULL;
        (*raiz) -> esquerda = NULL;
    } else {
        if ( num < (*raiz) -> valor){
            inserirSemRetorno ( &((*raiz) -> esquerda), num );
            /* O que significa isso aqui? &((*raiz) -> esquerda)
            1. eu quero pegar o conteudo da raiz para isso eu coloco o *raiz entre () / (*raiz)
            2. eu preciso pegar o campo esquerda, para isso eu envolvo entre parentese o ((*raiz) -> esquerda)
            3. ((*raiz) -> esquerda) me mostra o ponteiro da esquerda, e eu preciso pegar o endereço da esquerda para acessar o valor do número
            4. Então eu coloco & na frente de tudo isso para conseguir acessar esse endereço de memória
            */
        } else {
            inserirSemRetorno ( &((*raiz) -> direita), num );
        }
    }
}
void imprimir ( NoArv *raiz ){
    if ( raiz != NULL ){
        printf("%d", raiz -> valor);
        imprimir ( raiz -> esquerda);
        imprimir ( raiz -> direita);
    }
}
int main(){
    NoArv *raiz = NULL;
    inserirSemRetorno ( &raiz, 2);
    imprimir ( raiz );
}

