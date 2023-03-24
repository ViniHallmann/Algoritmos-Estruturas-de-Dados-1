#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_PESSOA_SIZE sizeof( char ) * 10 + sizeof( int ) * 2 + sizeof( void *) * 2
#define PREV              sizeof( char ) * 10 + sizeof( int ) * 2 
#define PROX              sizeof( char ) * 10 + sizeof( int ) * 2 + sizeof( void *)
#define NOME_SIZE         0
#define IDADE_SIZE        sizeof( char ) * 10 
#define TELEFONE_SIZE     sizeof( char ) * 10 + sizeof ( int ) 

int Menu ( void );
void *incluirDados( void *head, void *pPessoa );
//void *pegarDados ();
void listarDados ( void *head);
void *head = 0;
int main (){

    int escolha;
    void *pessoa;
    for ( ; ; ){
        escolha = Menu();
        switch ( escolha )
        {
        case 1: 
            pessoa = malloc ( TOTAL_PESSOA_SIZE );
            printf( "\tDigite o nome: " );
            scanf( "%s", ( char * )pessoa );
                
            printf( "\tDigite a idade: ");
            scanf( "%d", ( int * )((char*)pessoa + IDADE_SIZE));

            printf( "\tDigite o telefone: ");
            scanf( "%d", ( int * )((char*)pessoa +  TELEFONE_SIZE ));
                    
            printf("\tDados inseridos: \n");
            printf("\tNome: %s\n", (char*)pessoa);
            printf("\tIdade: %d\n", *(int *)((char*)pessoa +  IDADE_SIZE));
            printf("\tTelefone: %d", *(int*)((char*)pessoa +  TELEFONE_SIZE));
            head = incluirDados(head, pessoa);
            break;
        case 2: 
            listarDados(head);
            break;
        case 3: 
            exit(0);
            break;
        default:
            printf( "Erro" );
            break;
        }
    }
}
int Menu ( void ){
    int escolha;
    do {
        printf( "\n\t\tMENU\n" );
        printf( "\t1)Inclur nome;\n" );
        printf( "\t2)Listar pessoas;\n" );
        printf( "\t3)Sair.\n" );
        printf( "\tDigite sua escolha: " );
        scanf( "%d", &escolha );
   } while ( escolha <= 0 || escolha > 3 );
    getchar();
    return escolha;
}
void *incluirDados ( void *head, void *pPessoa ){
    //INSERIR NO INICIO
    if ( head == 0 ){   
        head = pPessoa;
        *(void ** )( head + PREV ) = NULL;
        *(void ** )( head + PROX ) = NULL;
        return head;
    } 
    //INSERIR NO INICIO SE O PRIMEIRO VALOR DO HEAD FOR MAIOR QUE O pPESSOA
    if ( strcmp ( ( char * )head ,  ( char * )pPessoa ) > 0 ){
        void *novoHead = pPessoa;
        * ( void ** )( novoHead + PREV ) = NULL;
        * ( void ** )( novoHead + PROX ) = head;
        * ( void ** )( head + PREV ) = novoHead;
        return novoHead;
    }
    else {
        void *novoHead = head;
        // PERCORRE O BUFFER
        while ( *( void ** )(novoHead + PROX) != NULL ) {
            if ( novoHead != NULL){
                //novoHead = *( void ** )novoHead ;
                novoHead = *( void ** )( novoHead + PROX );
            }
        }
        //INSERIR NO FINAL
        if ( * ( void ** )(novoHead + PROX) == NULL && strcmp ( ( char* ) head, ( char* ) pPessoa ) < 0){
            *( void ** )( pPessoa + PREV ) = novoHead;
            *( void ** )( novoHead + PROX ) = pPessoa;
            *( void ** )( pPessoa + PROX ) = NULL;
            return novoHead;
        }
        return novoHead;
    }
}

void listarDados ( void *head ){
    if ( head == 0 ) {
        printf("\n\tlista vazia\n");
        return;
    } 

    void *dados = head;
    printf( "\n\tLISTA DE DADOS \n" );
    while ( dados != NULL) { 
        printf( "\tNome: %s\n", ( char * )dados);
        printf( "\tIdade: %d\n", *( int * )( ( char * )dados + IDADE_SIZE ) );
        printf( "\tTelefone: %d\n", *( int * )( ( char * )dados + TELEFONE_SIZE ) );
        dados = *( void ** )(dados + PROX);
        
    }
}