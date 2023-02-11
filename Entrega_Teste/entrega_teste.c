#include <stdio.h>
#include <stdlib.h>

struct listNode_t{
    int valor;
    struct listNode_t *next;
}; typedef struct listNode_t lista_t;


lista_t *Cria_lista( void );
void InsereNoFim( int x, lista_t *lista );
void Imprime ( lista_t *lista );
void InverteLista( lista_t *lista);

int main(){

    lista_t *lista;
    lista = Cria_lista();

    // Teste 1: 
    //InsereNoFim( 1, lista ); InsereNoFim( 2, lista ); InsereNoFim( 3, lista ); InsereNoFim( 4, lista ); InsereNoFim( 5, lista );

    //Teste 2:
    //InsereNoFim( 1, lista ); InsereNoFim( 2, lista );

    //Teste 3: Lista vazia
    Imprime( lista );
    InverteLista ( lista );
    Imprime( lista );

}

lista_t *Cria_lista( void ){

    lista_t *inicio;
	inicio = ( lista_t* ) malloc ( sizeof ( lista_t ) );
	inicio -> next = NULL;
	return inicio;
}

void InsereNoFim( int x, lista_t *lista ){

    lista_t *nova, *fim;

    for ( fim = lista ; fim -> next != NULL; fim = fim -> next);

    nova = ( lista_t* ) malloc ( sizeof( lista_t ) );
    nova -> valor = x;
    nova -> next = fim -> next;
    fim-> next = nova;
}

void Imprime ( lista_t *lista ){

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

void InverteLista( lista_t *lista){

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