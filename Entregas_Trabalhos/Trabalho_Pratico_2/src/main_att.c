/*      Palindrome Linked List
Dado o cabeçalho de uma lista encadeada, retorne true se for um palíndromo ou falso caso contrário.*/

// VINÍCIUS HALLMANN M1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
}; typedef struct ListNode List;

bool isPalindrome ( List *pList1, List *pList2, int ListOneSize );
bool isPalindromeRestrito ( List *pList );
List *createList();
List *inverteList ( List *pList1, int ListOneSize );
void insertNumber ( int num, List *pList);
void printList ( List *pList );
void freeList( List *pList );
int listSize( List *pList );


int main(int argc, char const *argv[])
{
    List *newList, *newList2;
    newList = createList ();
    
    
    //TESTE 1: 
    insertNumber ( 1, newList);
    insertNumber ( 2, newList);
    insertNumber ( 2, newList);
    insertNumber ( 1, newList);
    insertNumber ( 0, newList);
    
    
    
    //TESTE 2:
    //insertNumber ( 1, newList);
    //insertNumber ( 2, newList);
    

    printf( "Lista 1: " );
    printList ( newList );

    newList2 = inverteList ( newList, listSize ( newList ) );
    printf( "Lista 1 Invertida: " );
    printList ( newList2 );
    
    if ( isPalindromeRestrito ( newList ) ){
        printf( "Verdadeiro" );
    } else {
        printf( "Falso" );
    }
    freeList ( newList );
    freeList ( newList2 );
    return 0;
}

List *createList(){
    List *pList;
    pList = ( List *) malloc ( sizeof ( List ) );
    pList -> next = NULL;
    return pList;
}

void insertNumber ( int num, List *pList){
    if ( num <= 0 || num > 9 ) return;
    
    List *newN; 
    newN = ( List *) malloc ( sizeof ( List ) );
    newN -> next = pList -> next;
    pList -> next = newN;
    newN -> val = num;
}

void printList ( List *pList ){
    List *p;
    for ( p = pList -> next; p != NULL; p = p -> next ){
        printf( "%d ", p -> val );
    }
    printf( "\n" );
}

int listSize( List *pList ){
    List *p;
    int counter = 0;
    for ( p = pList; p -> next != NULL; p = p -> next ){
        counter++;
    }
    return counter;
}

List *inverteList ( List *pList, int ListOneSize ){
    List *newList, *p1 = pList -> next;
    newList = createList ();

    for ( int i = 0; i < ListOneSize; i++ ){
        insertNumber( p1 -> val, newList );
        p1 = p1 -> next;
    }
    return newList;
}

bool isPalindromeRestrito ( List *pList ){
    int counter = listSize ( pList );
    List *pListOne = pList -> next, *pListTwo = inverteList ( pList , counter ) -> next;

    for ( int i = 0; i < counter; i++ ){
        if ( pListOne -> val == pListTwo -> val ){
            pListOne = pListOne -> next; 
            pListTwo = pListTwo -> next;
        } else {
            return false;
        }
    }
    return true;
}
void freeList( List *pList ) {
    List *pTemp;
    while ( pList != NULL){
        pTemp = pList;
        pList = pList -> next;
        free (pTemp);
    }
}
