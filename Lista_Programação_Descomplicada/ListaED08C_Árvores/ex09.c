// Escreva uma funcao que exclui todos os nos de uma arvore binaria de busca com ID par
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Node {
    int data, id;
    struct Node *left, *right;
};

struct Node *NewNode ( int number ){
    struct Node *newNode = malloc ( sizeof ( struct Node ) );
    newNode -> data = number;
    newNode -> left = NULL;
    newNode -> right = NULL;
    if ( rand () % 2 == 0)
        newNode -> id = 2;
    else 
        newNode -> id = 0;
    
    return newNode;
}

struct Node *InsertData ( struct Node *root, int data ) {
    if ( root == NULL ){
        root = NewNode ( data );
        return root;
    } else {
        if ( rand () % 2 == 0){
            root -> left = InsertData ( root -> left, data );
        } else {
            root -> right = InsertData ( root -> right, data );
        }
        return root;
    }
}

struct Node *CreateTree ( struct Node *root ){
    srand(time(NULL));
    for ( int i = 0; i < 10; i++){
        root = InsertData ( root, i);
    }
    return root;
}

void PrintTree ( struct Node *root ){
    if ( root != NULL ){
        printf ( "Nodo: %d id: %d\n", root -> data, root -> id );
        PrintTree ( root -> left );
        PrintTree ( root -> right );
    }
    
}

void SearchId ( struct Node *root, int id  ){
    if ( root != NULL ){
        if ( root -> id == id ){
            printf ( " %d ", root -> data );
        } 
        SearchId ( root -> left, id  );
        SearchId ( root -> right, id );
    }

}
int main (){
    struct Node *root = NULL;
    root = CreateTree ( root );
    printf("Árvore aleatória não-ordenada:\n");
    PrintTree ( root );
    printf ( "Árvore ID 1: \n");
    SearchId ( root, 0 );
    printf ( "\nÁrvore ID 2: \n");
    SearchId ( root, 2 );
}