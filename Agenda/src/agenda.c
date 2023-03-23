#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10*sizeof(char)+4*sizeof(int) 
int Menu ( void );
void *incluirDados( void *head, void *pPessoa );
void *pegarDados ();
void listarDados ( void *head);
void *head = 0;
int main (){

    int escolha;
    void *pessoa;
    for ( ;; ){
        escolha = Menu();
        switch ( escolha )
        {
        case 1: 
            incluirDados(&head, pegarDados());
            break;
        case 2: 
            listarDados(&head);
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
void *pegarDados (){

    void *pessoa;
    pessoa = malloc ( SIZE );
    printf( "Digite o nome: " );
    scanf( "%s", ( char * )pessoa );

    printf( "Digite a idade: ");
    scanf( "%d", ( int * )(pessoa + sizeof ( char * ) * 10 ));

    printf( "Digite o telefone: ");
    scanf( "%d", ( int * )(pessoa +  sizeof ( char * ) * 10  + sizeof ( int * ) ));

    pessoa += sizeof ( char * ) * 10 + sizeof ( int *) * 2; // andei 18 bytes ate chegar no final
    *( int *) pessoa = 0; // aponto para pessoa PREV
    pessoa += sizeof(int); // ando o tamanho do int
    *( int * ) pessoa = 0; // aponto para pessoa PROX
    pessoa -= sizeof ( char * ) * 10 + sizeof ( int *) * 3; // andei 22 bites, agora eu preciso voltar isso para apontar para o inicio da pessoa
    return &pessoa;
    // OBS. eu posso criar um ponteiro que aponta para o valor inicial e depois eu so coloco esse ponteiro em pessoa e retorno o inicio da pessoa
}
void *incluirDados ( void *head, void *pPessoa ){

    void *novoDado, *tempHead = *( int *)head;
    if ( head == 0 )
    {   
        head = pPessoa;
        return head;
    } 

    if ( strcmp ( head , pPessoa ) < 0 ){
        head = pPessoa;
        return head;
    }
}

void listarDados ( void *head ){

    if ( head == NULL ) {
        printf("lista vazia\n");
        return;
    } 
    
    void **dados = head;

    while( *dados != NULL ) {
        printf( "\n LISTA DE DADOS \n" );
        printf( "Nome: %s", ( char * )*dados );
        dados += sizeof( char ) * 10;
        printf( "Idade: %d",( int )*dados );
        dados += sizeof( int );
        printf( "Telefone: %d", ( int )*dados );
        dados += sizeof( int ) * 2;
    }
}
    /*
    while( pBuffer != NULL){
        printf("\n LISTA DE DADOS \n");
        printf("Nome: %s", ( char * ) pBuffer );
        printf("Idade: %d", ( int ) *( int * ) (*pBuffer + sizeof ( char ) * 10));
        printf("Telefone: %d", ( int ) *( int * ) (*pBuffer + sizeof ( char ) * 10 + sizeof (int) * 9));
    }*/
    
