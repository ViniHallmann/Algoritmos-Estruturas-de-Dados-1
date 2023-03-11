/*Faca uma funcao para remover os n primeiros elementos de uma lista. A funcao deve 
retornar se a operacao foi possıvel ou nao.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node *next;
}; typedef struct node list;

list* criaLista();
void insertElement(int element, list *pList);
void removeNElements(int N, list **pList);
int listSize(list *pList);
void imprime(list *pList);

int main(){
    list *list;
    list = criaLista();
    for(;;){
        int number;
        scanf("%d", &number);
        if (number == 0)
            break;
        insertElement(number,list);
        
    }
    imprime (list);
    printf("\n\n%d\n", listSize(list));
    removeNElements(2,list);
    imprime (list);
}

list* criaLista(){
    list* lFirst;
    lFirst = (list*) malloc (sizeof (list));
    lFirst -> next =  NULL;
    return lFirst;
}

void insertElement(int element, list *pList){

    list *newNode;
    newNode = (list*)malloc(sizeof(list));
    newNode -> next = pList -> next;
    pList -> next = newNode;
    newNode -> element = element;
}
int listSize(list *pList){
    list *list;
    int counter = 0;
    for (list = pList; list -> next != NULL; list = list -> next ){
        counter++;
    }
    return counter;
}

void imprime(list *pList){
    list *list;
    for(list = pList -> next; list != NULL; list = list -> next){
        printf("%d ", list -> element);
    }
}

void removeNElements(int N, list **pList){
    list *routeList, *routeNext;
    int counter = 0;

    routeList = *pList;

    while (counter < N && routeList != NULL){

        routeNext = routeList -> next;
        free( routeList );
        routeList = routeNext;
        counter++;
    }
    (*pList) -> next = routeList;
}





