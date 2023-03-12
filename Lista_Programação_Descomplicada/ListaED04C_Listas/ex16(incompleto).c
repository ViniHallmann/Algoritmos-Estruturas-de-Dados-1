/*Fazer uma funcao que copia uma lista L1 em uma outra lista L2*/
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int element;
    struct list *next;
} LIST;

LIST *CreateList();
void InsertElement (int element, LIST *pList);
void PrintList (LIST *pList);
int ListOneSize(LIST *pList);
LIST *copyList (LIST *pList1, LIST *pList2, int ListOneSize);

int main(){
    LIST *list1 = CreateList(), *list2 = CreateList();
    InsertElement(1, list1);
    InsertElement(2, list1);
    InsertElement(3, list1);
    printf("List 1: ");
    PrintList(list1);
    printf("\nList 2: ");
    list2 = copyList(list1, list2, ListOneSize(list1));
    PrintList(list2);
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
    //pList = newP;
    newP -> element = element;
}

int ListOneSize(LIST *pList){
    LIST *p;
    int counter = 0;
    for (p = pList -> next ; p != NULL; p = p -> next){
        counter++;
    }
    return counter;
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

LIST *copyList (LIST *pList1, LIST *pList2, int ListOneSize){
    LIST *p1 = pList1 -> next;

    for (int i = 0; i < ListOneSize; i++){
        InsertElement(p1 -> element, pList2);
        p1 = p1 -> next;
    }
    /*while (p1 != NULL){
        InsertElement(p1 -> element, p2);
        p1 = p1 -> next;
    }*/
    return pList2 ;
}