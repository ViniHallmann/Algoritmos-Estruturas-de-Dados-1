/*Faca uma funcao para buscar a posicao e o valor do maior elemento da lista, os quais
deverao ser retornados por referencia. A funcao deve retornar se a operacao foi possıvel ou nao.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int element;
    struct list *next;
} LIST;

LIST *CreateList();
void InsertElement (int element, LIST *pList);
void PrintList (LIST *pList);
void WhichIsBigger(LIST *pList);

int main(){
    LIST *list = CreateList();
    InsertElement(1, list);
    InsertElement(2, list);
    InsertElement(3, list);
    PrintList(list);
    WhichIsBigger(list);
}

LIST *CreateList(){
    LIST *start;

    start = ( LIST *) malloc ( sizeof ( LIST ) );
    start -> next = NULL;
    return start;
}

void InsertElement (int element, LIST *pList){
    LIST *newP;
    newP = ( LIST * ) malloc ( sizeof ( LIST) );
    newP -> next = pList -> next;
    pList -> next = newP;
    newP -> element = element;
}

void PrintList (LIST *pList){
    LIST *p;

    for (p = pList -> next; p != NULL; p = p -> next){
        if (p -> next == NULL){
            printf("%d ", p -> element);
        } else{
            printf("%d -> ", p -> element);
        }
    }
}

void WhichIsBigger(LIST *pList){
    LIST *p = pList -> next, *pos;

    if (pList == NULL || (pList)->next == NULL) {
        printf("Lista vazia ou com apenas um elemento.\n");
        return;
    } else {
        printf("\nOperação realizada com sucesso!");
    }

    int tempHigh = p -> element;
    for (p = pList -> next; p != NULL; p = p -> next){
        if (p -> element > tempHigh){
            tempHigh = p -> element;
            pos = p;
        }
            
    }
    printf("\nO maior valor da lista é %d na memória %p", tempHigh, pos);
}