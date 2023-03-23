#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_PESSOA_SIZE sizeof( char ) * 11 + sizeof( int ) * 2 + sizeof( void *) * 2
#define PREV_SIZE  sizeof( char ) * 11 + sizeof( int ) * 2 
#define PROX_SIZE  sizeof( char ) * 11 + sizeof( int ) * 2 + sizeof( void *)
#define NOME_SIZE 0
#define IDADE_SIZE sizeof( char ) * 11 
#define TELEFONE_SIZE sizeof( char ) * 11 + sizeof ( int ) 

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
            
            printf("\tDados inseridos: ");
            printf("%s ", (char*)pessoa);
            printf("%d ", *(int *)((char*)pessoa +  IDADE_SIZE));
            printf("%d", *(int*)((char*)pessoa +  TELEFONE_SIZE));
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
        printf( "\t3)Apagar pessoa;\n" );
        printf( "\t4)Sair.\n" );
        printf( "\tDigite sua escolha: " );
        scanf( "%d", &escolha );
   }while ( escolha <= 0 || escolha > 5 );
    getchar();
    return escolha;
}
void *incluirDados ( void *head, void *pPessoa ){

    if ( head == 0 ){   
        head = pPessoa;
        *(void **)(head + sizeof(char)*10 + sizeof(int)*2) = NULL;
        
        *(void **)(head + sizeof(char)*10 + sizeof(int)*2 + sizeof(void*)) = NULL;
        
        return head;
    } 

    /*if ( strcmp ( head , pPessoa ) < 0 ){
        head = pPessoa;
        return head;*/
    else {
        void *novoHead = pPessoa;
        while ( *(void**) head != NULL) {
            head += 10*sizeof(char)+2*sizeof(int)+sizeof(void*);
            if(*(void**)head != NULL){
                head = *(void**)head;
            }
        }
        *(void**)(novoHead + 10*sizeof(char)+2*sizeof(int)) = head;
        *(void**)(novoHead+ 10*sizeof(char)+2*sizeof(int)+ sizeof( void*)) = *(void**)(head+10*sizeof(char)+2*sizeof(int)+ sizeof( void*));
        *(void**)(head+10*sizeof(char)+2*sizeof(int)+ sizeof( void*)) = novoHead;

        return novoHead;
    }


}

void listarDados ( void *head ){

    if ( head == 0 ) {
        printf("\tlista vazia\n");
        return;
    } 
    
    void *dados = head;
    
   while (*(void**)dados != NULL) {
        printf("\n LISTA DE DADOS \n");
        printf("Nome: %s\n", (char*)dados);
        printf("Idade: %d\n", *(int *)((char*)dados + IDADE_SIZE));
        printf("Telefone: %d\n", *(int*)((char*)dados + TELEFONE_SIZE));
        
        //dados += (10 * sizeof(char) + 2 * sizeof(int) + sizeof ( void* ));
        dados += TOTAL_SIZE;
        if ( *(void**)dados != NULL){
            dados = *(void**)dados;
        }
    }
}
    
/*
void *incluirDados(void *head, void *pPessoa) {
    if (head == NULL) {
        head = pPessoa;
        return head;
    }

    void *atual = head;
    void **pAnterior = &head;

    while (atual != NULL && strcmp(atual, pPessoa) < 0) {
        pAnterior = atual;
        atual = *(void **)atual;
    }

    *(void **)pPessoa = atual;
    *pAnterior = pPessoa;

    return head;
}
void listarDados ( void *head ){
    if ( head == 0 ) {
        printf("\tlista vazia\n");
        return;
    } 

    void *dados = head;
    
    while( dados != NULL ) {
        printf( "\n LISTA DE DADOS \n" );
        printf( "Nome: %s", ( char * ) dados );
        printf( "Idade: %d", *(int*)((char*)dados + 10*sizeof(char)));
        printf( "Telefone: %d", *(int*)((char*)dados + 10*sizeof(char) + sizeof(int)));
        dados = *(void**)((char*)dados + 10*sizeof(char) + 2*sizeof(int));
    }
}

void listarDados(void *head) {
    if (head == NULL) {
        printf("\tlista vazia\n");
        return;
    }

    void **pHead = (void**)&head;
    void *pElemento = head;

    printf("\n LISTA DE DADOS \n");

    while (pElemento != NULL) {
        char *nome = (char*)pElemento;
        int idade = *(int*)((char*)pElemento + strlen(nome) + 1);
        int telefone = *(int*)((char*)pElemento + strlen(nome) + 1 + sizeof(int));

        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Telefone: %d\n", telefone);

        pElemento = *(void**)pElemento;
    }
}*/

