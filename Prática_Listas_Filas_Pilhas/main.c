#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    struct Celula *prev;
    int conteudo;
    struct Celula *next;
}Celula;


void RESET(Celula *head)
{
    head->prev = NULL;
    head->conteudo = 0;
    head->next = NULL;

}

void PUSH(Celula *head, int dado)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    Celula **aux = &(head)->next;

    nova->conteudo = dado;
    if(head->next == NULL)
    {

        nova->next = head->next;
        head->next = nova;
        nova->prev = head;

    }
    else
    {

        nova->next = head->next;
        (*aux)->prev = nova;
        head->next = nova;
        nova->prev = head;
        
    }

}

void PRINTLIST(Celula *head)
{
    Celula **aux = &head;

    while((*aux)->next)
    {
        aux = &(*aux)->next;
        printf("%d ",(*aux)->conteudo);
    }

    while((*aux)->prev && (*aux)->conteudo != 0)
    {
        printf("%d ",(*aux)->conteudo);
        aux = &(*aux)->prev;
        
    }

    printf("\n");
}

void POP(Celula *head)
{
    Celula **aux = &(head)->next;
    Celula *rm;

    if(head->next != NULL)
    {
        rm = head->next;
        head->next = (*aux)->next;
        (*aux)->prev = head;
        
    }

    free(rm);
}

int main(int argc, char const *argv[])
{
    Celula *head = (Celula *)malloc(sizeof(Celula));

    RESET(head);

    PUSH(head,1);
    PUSH(head,2);
    PUSH(head,3);

    PRINTLIST(head);

    PUSH(head,4);

    PRINTLIST(head);
    POP(head);
    PRINTLIST(head);

    return 0;
}
