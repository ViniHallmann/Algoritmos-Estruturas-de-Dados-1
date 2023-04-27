#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* sortList( struct ListNode* head ){

    if ( head == NULL || head -> next == NULL ){
        return head;
    }

    struct ListNode *ip;
    for ( ip = head; ip -> next != NULL; ip = ip -> next ){
        struct ListNode *smallerNode = ip, *jp;
        for ( jp = ip -> next; jp != NULL; jp = jp -> next ){
            if ( smallerNode -> val > jp -> val ){
                smallerNode = jp;
            }
        }
        int aux = ip -> val;
        ip -> val = smallerNode -> val;
        smallerNode -> val = aux;
    }
    return head;
}