/*Implemente a funcao reverso, que reposiciona os elementos na fila de tal forma que 
o inıcio da fila torna-se o fim, e vice-versa*/

#include <stdio.h>
#include <stdlib.h>

/*struct Sentry {
    queue *pFirst;
    queue *pLast;
};*/
struct QueueList {
    int number;
    struct QueueList *next;
}; typedef struct QueueList queue;

queue *createQueue ();
queue *reverseQueue ( int counter, queue *pQueue );
int isEmpty ( queue *pQueue);
int queueSize( queue *pQueue);
void printQueue( queue *pQueue);
void inserElement ( int element, queue *pQueue );


int main(){
    queue *newQueue  =  createQueue ();
    inserElement ( 1, newQueue );
    inserElement ( 2, newQueue );
    inserElement ( 3, newQueue );
    inserElement ( 4, newQueue );
    printQueue ( newQueue );
    reverseQueue ( queueSize ( newQueue), newQueue );
    printQueue ( newQueue );
}

queue *createQueue (){
    queue *pQueue;
    pQueue = ( queue *) malloc ( sizeof ( queue ) );
    pQueue -> next = NULL;
    return pQueue;
}
int isEmpty ( queue *pQueue ){
    if (pQueue -> next == NULL)
        return 1;
    else 
        return 0;
}
void inserElement ( int element, queue *pQueue){
    queue *newQ, *pEnd = pQueue;
    newQ = ( queue* ) malloc ( sizeof ( queue ) );

    while (pEnd -> next != NULL){
        pEnd = pEnd -> next;
    }
    pEnd -> next = newQ;
    newQ -> number = element;
    newQ -> next = NULL;

}
void printQueue( queue *pQueue){
    queue *p;

    for ( p = pQueue -> next; p != NULL; p = p -> next){
        printf("%d ", p -> number);
    }
    printf("\n");
}
int queueSize( queue *pQueue){
    queue *p;
    int counter = 0;
    for ( p = pQueue; p -> next != NULL; p = p -> next){
        counter++;
    }
    return counter;
}
queue *reverseQueue(int counter, queue *pQueue) {
    queue *pCurr = pQueue->next;
    queue *pPrev = NULL;
    queue *pNext = NULL;

    while (pCurr != NULL && counter > 0) {
        pNext = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
        counter--;
    }

    pQueue->next = pPrev;

    return pQueue;
}