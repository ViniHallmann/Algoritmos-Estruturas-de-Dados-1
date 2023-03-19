#include <stdio.h>
#include <stdlib.h>

struct sNode {
    int info;
    struct sNode *next;
}; typedef struct sNode node;

struct sQueue {
    node *pFirst;
    node *pLast;
}; typedef struct sQueue queue;

node *createNode(){
    node *newNode = ( node * ) malloc ( sizeof ( node ) );
    newNode -> next = NULL;
    return newNode;
}
void startQueue ( queue *pQueue ){
    pQueue -> pFirst = NULL;
    pQueue -> pLast = NULL;
}
int isEmpty ( queue *pQueue ){
    if ( pQueue -> pFirst == NULL && pQueue -> pLast == NULL )
        return 1;
    else 
        return 0;
}
int pushElement ( int element, queue *pQueue ){
    node *newNode = createNode(); // FILA EXEMPLO: nodo
    newNode -> info = element; // nodo (1)
    if ( isEmpty ( pQueue ) == 1){
        pQueue -> pFirst = newNode; // nodo (1) é o inicio e o fim tambem
        pQueue -> pLast = newNode;
        return 1;
    }
    pQueue -> pLast -> next = newNode;// O que essa linha quer dizer é que o próximo do ultimo elemento vai apontar para o novo elemento 
    pQueue -> pLast = newNode;
    return 1;
}
int popElement ( queue *pQueue){
    node *tempNode = pQueue -> pFirst; // Recebe o primeiro da fila
    int element = pQueue -> pFirst -> info;
    if ( pQueue -> pFirst == NULL){
        printf("Fila Vazia!");
        return 0;
    } else {
        pQueue -> pFirst = pQueue -> pFirst -> next; // o primeiro da fila recebe o proximo do primeiro da fila
    }
    free (tempNode); // remove o primeiro
    return element;
}
void printQueue ( queue *pQueue ){
    node *p;
    for ( p = pQueue -> pFirst; p != NULL; p = p -> next ){
        printf( "%d ", p -> info );
    }
    printf("\n");
}

queue *reverseQueue ( queue *pQueue ){
    queue *newQueue = ( queue *) malloc ( sizeof ( queue ) );;
    node *pCurr = pQueue -> pFirst, *pNext = NULL, *pPrev = NULL, *setLast;
    startQueue ( newQueue );

    while (pCurr!= NULL){
        pNext = pCurr -> next;
        pCurr -> next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    newQueue -> pFirst = pPrev;
    for (setLast = newQueue -> pFirst; setLast -> next != NULL; setLast = setLast -> next){
        newQueue -> pLast = setLast;
    }
    return newQueue;
    /*
    while(pCurr != NULL){

        pushElement (pCurr -> info, newQueue );
        pCurr = pCurr -> next;

    }
    
    while (newQueue->pFirst != NULL) {
        pNext = newQueue->pFirst->next;
        newQueue->pFirst->next = pPrev;
        pPrev = newQueue->pFirst;
        newQueue->pFirst = pNext;
    }
    newQueue->pFirst = pPrev;
    newQueue->pLast = pQueue->pFirst;*/
}

int main(){
    queue *newQueue = ( queue *) malloc ( sizeof ( newQueue ) );
    startQueue ( newQueue );
    pushElement ( 1, newQueue );
    pushElement ( 2, newQueue );
    pushElement ( 3, newQueue );
    pushElement ( 4, newQueue );
    pushElement ( 5, newQueue );
    printQueue ( newQueue );
    queue *reversedQueue = reverseQueue ( newQueue );
    printQueue ( reversedQueue );
}




