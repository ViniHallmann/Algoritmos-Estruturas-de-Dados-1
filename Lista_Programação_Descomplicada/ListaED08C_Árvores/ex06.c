//Escreva uma funcao para buscar um numero impar em uma arvore binaria NAO ordenada.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Node {
    int number;
    struct Node *left, *right;
};

struct Node *NewNode ( int number ){
    struct Node *newNode = malloc ( sizeof ( struct Node ) );
    newNode -> number = number;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct Node *InsertNumber ( struct Node *root, int number ){
    if ( root == NULL ){
        root = NewNode ( number );
        return root;
    } else {
        if ( rand () % 2 == 0){
            root -> left = InsertNumber ( root -> left, number );
        } else {
            root -> right = InsertNumber ( root -> right, number );
        }
        return root;
    }
}

struct Node *CreateTree ( struct Node *root ){
    srand(time(NULL));
    for ( int i = 0; i < 10; i++){
        root = InsertNumber ( root, i);
    }
    return root;
}

void PrintTree ( struct Node *root ){
    if ( root != NULL ){
        PrintTree ( root -> left );
        printf( " %d ", root -> number );
        PrintTree ( root -> right );
    }
}

void SearchOddNumbers ( struct Node *root ){
    if ( root != NULL ){
       if ( root -> number % 2 == 1 ){
            printf ( " %d ", root -> number );
        }
        SearchOddNumbers ( root -> left );
        SearchOddNumbers ( root -> right ); 
    }
    
}
int main (){
    struct Node *root = NULL;
    root = CreateTree ( root );
    printf("Árvore aleatória não-ordenada:\n");
    PrintTree ( root );
    printf("\nSomente os valores ímpares da árvore aleatória não-ordenada:\n");
    SearchOddNumbers ( root );
}