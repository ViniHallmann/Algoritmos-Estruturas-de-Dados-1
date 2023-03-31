/*Generalize o conceito de lista circular para Lista Circular Duplamente Encadeada. Implemente as func¸oes necessarias para o gerenciamento da mesma. */

#include <stdio.h>
#include <stdlib.h>

struct listDP {
    int num;
    struct listDP *next;
    struct listDP *prev;
}; typedef struct listDP list;

list *start;
list *end;
list *createList(){
    list *newList;
    newList = (list *) malloc ( sizeof ( list ) );
    newList -> next = NULL;
    newList -> prev = NULL;
    //tamanho = 0;
}