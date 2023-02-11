#include <stdio.h>
#include <stdlib.h>

struct listNode_t{

    int valor;

    struct listNode_t *next;

}; typedef struct listNode_t lista_t;


lista_t *cria_lista( void );

void insereNoFim( int x, lista_t *lista );

void imprime ( lista_t *lista );

void inverteLista( lista_t *lista);

int main(){

    lista_t *lista;

    lista = cria_lista();

    // Teste 1: 
    insereNoFim( 1, lista ); insereNoFim( 2, lista ); insereNoFim( 3, lista ); insereNoFim( 4, lista ); insereNoFim( 5, lista );

    //Teste 2:
    //insereNoFim( 1, lista ); insereNoFim( 2, lista );

    //Teste 3: Lista vazia


    imprime( lista );

    inverteLista ( lista );

    imprime( lista );

}

lista_t *cria_lista( void ){

    lista_t *inicio;

	inicio = ( lista_t* ) malloc ( sizeof ( lista_t ) );

	inicio -> next = NULL;

	return inicio;

}

void insereNoFim( int x, lista_t *lista ){

    lista_t *nova, *fim;

    for ( fim = lista ; fim -> next != NULL; fim = fim -> next);

    nova = ( lista_t* ) malloc ( sizeof( lista_t ) );

    nova -> valor = x;

    nova -> next = fim -> next;

    fim-> next = nova;

}

void imprime ( lista_t *lista ){

	lista_t *p;

    if ( lista -> next == NULL ){

        printf("Lista vazia");

    } else {

        for( p = lista -> next; p != NULL; p = p -> next ){

		printf("%d ", p -> valor);
        

	    }
        
        printf("\n");
    }	
}

void inverteLista( lista_t *lista){

    lista_t *p, *q;

    int contadorDeItens = -1, tempVariavel;

    p = lista;

    q = lista -> next;

    for( p = lista; p -> next != NULL; p = p -> next ){

        contadorDeItens++;

        contadorDeItens = -1;

    }
    
    do{
        tempVariavel = p -> valor;

        p -> valor = q -> valor;

        q -> valor = tempVariavel;

        p = q;

        q = q -> next;
        
        contadorDeItens--;

    }while( contadorDeItens > 0 );

}