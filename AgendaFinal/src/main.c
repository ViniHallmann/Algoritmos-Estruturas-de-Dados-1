/*
----------- TRABALHO AGENDA | Vinícius Hallmann | Turma M1 -----------
• Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
• Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
• Todos os dados do programa devem ser guardados dentro do pBuffer.
• Não pode usar struct em todo o programa.
• Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
• Implementar a base de dados da agenda usando lista duplamente ligada
• Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
• Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definições dos tamanhos usados 
#define TOTAL_PESSOA_SIZE sizeof( char ) * 10 + sizeof( int ) * 2 + sizeof( void *) * 2
#define PREV              sizeof( char ) * 10 + sizeof( int ) * 2 
#define PROX              sizeof( char ) * 10 + sizeof( int ) * 2 + sizeof( void *)
#define NOME_SIZE         0
#define IDADE_SIZE        sizeof( char ) * 10 
#define TELEFONE_SIZE     sizeof( char ) * 10 + sizeof ( int ) 

// Chamada das funções
void *incluirDados( void *head, void *pPessoa );
void *pegarDados ();
void listarDados ( void *head);
void menu ();

// Funções
int main (){
    void *head = 0;
    menu( head );
}
void menu ( void *head){
    for ( ; ; ){
        printf( "\n\t\tMENU\n" );
        printf( "\t1)Inclur nome;\n" );
        printf( "\t2)Listar pessoas;\n" );
        printf( "\t3)Sair.\n" );
        printf( "\tDigite sua escolha: " );

        switch ( getchar () )
        {
        case '1': 
            head = incluirDados( head, pegarDados() );
            getchar();
            break;
        case '2': 
            listarDados( head );
            getchar();
            break;
        case '3': 
            exit( 0 );
            getchar();
            break;
        default:
            printf( "\n\n\tERRO. Tente novamente!\n" );
            break;
        }
    }
}
void *pegarDados (){
    //PEGA OS DADOS DA PESSOA QUE VAI SER INSERIDA NO pBUFFER
    void *pessoa = malloc ( TOTAL_PESSOA_SIZE );

    printf( "\tDigite o nome: " );
    scanf( "%s", ( char * )pessoa );

    printf( "\tDigite a idade: ");
    scanf( "%d", ( int * )((char*)pessoa + IDADE_SIZE));
    while ( *( int * )((char*)pessoa + IDADE_SIZE)  < 0 || *( int * )((char*)pessoa + IDADE_SIZE) > 99){
        printf("\n\tERRO. Tente novamente!\n");
        printf( "\n\tDigite a idade: ");
        scanf( "%d", ( int * )((char*)pessoa + IDADE_SIZE));
    }

    printf( "\tDigite o telefone: ");
    scanf("%d", ( int * )((char*)pessoa + TELEFONE_SIZE));
    /*do{            
        scanf("%9s",( (char*)pessoa + TELEFONE_SIZE));

    } while (strlen((char*)pessoa + TELEFONE_SIZE) != 9);*/

    return pessoa;
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
        if ( * ( void ** )( novoHead + PROX ) == NULL && strcmp ( ( char* ) head, ( char* ) pPessoa ) < 0){
            *( void ** )( pPessoa + PREV ) = novoHead;
            *( void ** )( novoHead + PROX ) = pPessoa;
            *( void ** )( pPessoa + PROX ) = NULL;
            return head;
        }
        //INSERIR NO MEIO
        if (* ( void ** )( novoHead + PROX ) != NULL && strcmp ( ( char* ) head, ( char* ) pPessoa ) > 0){
            void *tempPREV = (novoHead + PREV);
            void *tempPROX = (tempPREV + PROX);
            *( void ** )( pPessoa + PREV ) = tempPREV;
            *( void ** ) tempPROX = pPessoa;
            *( void ** )( novoHead + PREV ) = pPessoa;
            *( void ** )( pPessoa + PROX ) = novoHead;
            return head;
        }
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
        printf( "\tNome: %s\n", ( char * )dados );
        printf( "\tIdade: %d\n", *( int * )( ( char * )dados + IDADE_SIZE ) );
        printf( "\tTelefone: %d\n", *( int * )( ( char * )dados + TELEFONE_SIZE ) );
        dados = *( void ** )( dados + PROX );
        
    }
}