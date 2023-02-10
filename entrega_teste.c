#include <stdio.h>

struct listNode_t{
    int val;
    struct listNode_t *next;
}; typedef struct listNode_t lista_t;

lista_t *head;
lista_t *p, *q;

/*
====================
ReverseList
Esta função recebe o head de uma lista e percorre a mesma até o final para contar quantos valores existem na lista.
Depois ela percorre essa lista com as variaveis (p) e (q) invertendo o numero de (p) com (q) até chegar no final da lista. 
(Este processo é repetido X vezes o número de valores que esta lista contém).
====================
*/

struct listNode_t* ReverseList(struct listNode_t* head){
    
    int contadorDeValores = 0;

    if ( head == NULL ){
        return head;
    }

    for( p = head; p -> next != NULL; p = p -> next ){
        contadorDeValores++;
    }

    p = head;
    q = head -> next;

    do{
        ( q -> next != NULL );
        p -> val = q -> val;
        p = q;
        q = q -> next;
        contadorDeValores--;
    }while( contadorDeValores != 0 );

    for( p = head -> next; p != NULL; p = p-> next ){
        printf("%d\n", p -> val);
    }
}


