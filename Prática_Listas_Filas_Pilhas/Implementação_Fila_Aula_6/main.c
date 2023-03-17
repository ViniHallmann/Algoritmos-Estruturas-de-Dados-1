#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct lista{
    SNodo *pFirst;
    SNodo *pLast;
}; typedef struct lista SFila;

struct nodo{
    Sinfo dado;
    struct nodo *pNext;
    struct nodo *pPrevious;
};typedef struct nodo SNodo;

struct info {
    int cod;
    char nome [40];
    float preco;
}; typedef struct info Sinfo;

SFila *Reset ( SFila *pOldFila);
int Pop ( SFila *pFila, Sinfo *pInfo);
void Push ( SFila *pFila, Sinfo *pInfo);
void imprimeFila ( SFila *pFila);

int main (){
    SFila *fila;
    Sinfo *info;
    info -> cod = 1;
    strcpy (info -> nome, "Teste");
    info -> preco = 2;
    Reset ( fila );
    Push ( fila, info );
    imprimeFila ( fila );
}

SFila *Reset ( SFila *pOldFila){

    if (pOldFila){
        Clear(pOldFila);
    }

    SFila *pFila;

    pFila = (SFila *) malloc (sizeof (SFila) );
    pFila -> pFirst = NULL;
    pFila -> pLast = NULL;

    return pFila;
}

void Push ( SFila *pFila, Sinfo *pInfo){
    SNodo *pNovo;
    pNovo = (SNodo *) malloc (sizeof ( SNodo ) );
    pNovo -> dado = pInfo;
    pNovo -> pNext = NULL;

    if (pFila -> pLast != NULL)
        pFila -> pLast -> pNext = pNovo;
    else 
        pFila -> pFirst = pNovo;
    pFila -> pLast = pNovo;
}

int Pop ( SFila *pFila, Sinfo *pInfo){
    SNodo *pNodo;

    if ( pFila -> pFirst == NULL){
        printf("Fila Vazia!");
        return 0;
    }
    
    else {
        pNodo = pFila -> pFirst;
        *pInfo = pFila -> pFirst -> dado;
        pFila -> pFirst = pFila -> pFirst -> pNext;
    }

    if ( pFila -> pFirst == NULL){
        pFila -> pLast = NULL;
    }

    free (pNodo);
    return 1;
}

void imprimeFila ( SFila *pFila){
    SNodo *pNodo;

    if ( pFila -> pFirst == NULL){
        printf("Fila Vazia!");
    }

    else {
        for ( pNodo = pFila -> pFirst; pNodo != NULL; pNodo = pNodo -> pNext){
            printf( "Nome %c cod = %d preco = %3.2f", pNodo -> dado.nome , pNodo -> dado.cod , pNodo -> dado.preco);
        }
    }
}