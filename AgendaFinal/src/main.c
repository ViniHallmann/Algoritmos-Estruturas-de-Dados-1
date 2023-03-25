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
void *PegarDados   ();
void *IncluirDados ( void *head, void *dadosPessoa );
void *RemoverDados ( void *head, void *dadosPessoa );
void ListarDados   ( void *head );
void BuscarDados   ( void *head );
void *LimparLista  ( void *head );
void Menu          ( void *head );


// Funções
int main (){
    void *head = malloc( 0 );
    head = 0;
    Menu( head );
}

void Menu ( void *head ){
    for ( ; ; ){
        printf( "\n\t\tMENU\n" );
        printf( "\t1)Incluir nome;\n" );
        printf( "\t2)Listar pessoas;\n" );
        printf( "\t3)Buscar pessoa;\n" );
        printf( "\t4)Remover dados\n" );
        printf( "\t5)Limpar todos os dados da agenda;\n" );
        printf( "\t6)Sair.\n" );
        printf( "\tDigite sua escolha: " );

        switch ( getchar () )
        {
        case '1': 
            head = IncluirDados( head, PegarDados() );
            getchar();
            break;
        case '2': 
            ListarDados( head );
            getchar();
            break;
        case '3': 
            BuscarDados( head );
            getchar();
            break;
        case '4': 
            head = RemoverDados ( head, PegarDados() );
            getchar();
            break;
        case '5': 
            head = LimparLista( head );
            getchar();
            break;
        case '6':
            head = LimparLista( head );
            free( head );
            exit( 0 );
            getchar();
            break;
        default:
            printf( "\n\n\tERRO. Tente novamente!\n" );
            break;
        }
    }
}
/*
====================
PegarDados
    PEGA OS DADOS DA PESSOA( NOME,IDADE,TELEFONE ) QUE VÃO SER INSERIDAS NO BUFFER
====================
*/
void *PegarDados (){

    void *pessoa = malloc ( TOTAL_PESSOA_SIZE );

    printf( "\tDigite o nome: " );
    scanf( "%s", ( char * )pessoa );

    printf( "\tDigite a idade: " );
    scanf( "%d", ( int * )( ( char* )pessoa + IDADE_SIZE ) );

    while ( *( int * )( ( char* )pessoa + IDADE_SIZE )  < 0 || *( int * )( ( char* )pessoa + IDADE_SIZE ) > 99 ){
        printf( "\n\tERRO. Tente novamente!\n" );
        printf( "\n\tDigite a idade: ");
        scanf( "%d", ( int * )( ( char* )pessoa + IDADE_SIZE ) );
    }

    printf( "\tDigite o telefone: " );
    scanf( "%d", ( int * )( ( char* )pessoa + TELEFONE_SIZE ) );

    return pessoa;
}
/*
====================
IncluirDados
    INCLUI OS DADOS DA PESSOA NO BUFFER
====================
*/
void *IncluirDados ( void *head, void *dadosPessoa ){
    //Insere no inicio da head
    if ( head == 0 ){   
        head = dadosPessoa;
        *(void ** )( head + PREV ) = NULL;
        *(void ** )( head + PROX ) = NULL;
        return head;
    } 
    //Inserir dados no inicio se o primeiro valor for "maior" que dadosPessoa
    if ( strcmp ( ( char * )head ,  ( char * )dadosPessoa ) > 0 ){
        void *novoHead = dadosPessoa;
        *( void ** )( novoHead + PREV ) = NULL;
        *( void ** )( novoHead + PROX ) = head;
        *( void ** )( head + PREV ) = novoHead;
        return novoHead;
    }
    else {
        void *novoHead = head;
        //Percorre o Buffer
        while ( *( void ** )( novoHead + PROX ) != NULL ) {
            if ( novoHead != NULL){
                novoHead = *( void ** )( novoHead + PROX );
                //Insere no meio do pBuffer
                if (  strcmp ( ( char* ) novoHead, ( char* ) dadosPessoa ) > 0 ){
                    void *tempPREV = *( void ** )( novoHead + PREV );
                    void *tempPROX = novoHead;
                    *( void ** )( dadosPessoa + PREV ) = tempPREV;
                    *( void ** )( dadosPessoa + PROX ) = novoHead;
                    *( void ** )( tempPROX + PREV) = dadosPessoa;
                    *( void ** )( tempPREV + PROX ) = dadosPessoa;
                    return head;
                }
            }
        }
        //Insere no final do pBuffer
        *( void ** )( dadosPessoa + PREV ) = novoHead;
        *( void ** )( novoHead + PROX ) = dadosPessoa;
        *( void ** )( dadosPessoa + PROX ) = NULL;
        return head;
    }
}
/*
====================
ListarDados
    lISTA TODOS OS DADOS DAS PESSOAS NO BUFFER
====================
*/
void ListarDados ( void *head ){
    //Retorna nada se a lista estiver vazia
    if ( head == NULL ) {
        printf( "\n\tAgenda vazia\n" );
        return;
    } 
    void *dados = head;
    //Lista os dados 
    printf( "\n\tLISTA DE DADOS \n" );
    while ( dados != NULL ) { 
        printf( "\tNome: %s\n", ( char * )dados );
        printf( "\tIdade: %d\n", *( int * )( ( char * )dados + IDADE_SIZE ) );
        printf( "\tTelefone: %d\n", *( int * )( ( char * )dados + TELEFONE_SIZE ) );
        dados = *( void ** )( dados + PROX );
    }
}
/*
====================
BuscarDados
    BUSCA O DADO DE UMA PESSOA NO BUFFER
====================
*/
void BuscarDados ( void *head ){
    void *buscaHead = head;
    void *pPessoa = malloc ( NOME_SIZE );

    printf( "\tDigite o nome: " );
    scanf( "%s", ( char * )pPessoa );

    if ( head == 0 ) {
        printf( "\n\tAgenda vazia\n" );
        return;
    }
    
    while ( *( void ** )buscaHead  != NULL ){ //Percorre a lista
        if ( buscaHead != NULL){  
            if ( strcmp ( ( char* ) buscaHead, ( char* ) pPessoa ) == 0 ){ //Compara o valor do dado com o valor na lista e vê se os dois são iguais, se sim, imprime os dados, se não, continua percorrendo a lista
                printf("\n\t'%s' está na agenda. O telefone de %s é: %d\n", ( char * )buscaHead, ( char * )buscaHead, *( int * )( ( char * )buscaHead + TELEFONE_SIZE )  );
                break;
            }
            buscaHead = *( void ** )( buscaHead + PROX );   
        }
    }
    /*
    void *pessoasEncontradas = malloc ( TOTAL_PESSOA_SIZE );
    while ( *( void ** )buscaHead  != NULL ){
        if ( buscaHead != NULL){  
            if ( strcmp ( ( char* ) buscaHead, ( char* ) pPessoa ) == 0 ){ //Compara o valor do dado com o valor na lista e vê se os dois são iguais, se sim, imprime os dados, se não, continua percorrendo a lista
                pessoasEncontradas = IncluirDados( pessoasEncontradas, buscaHead );
            }
            buscaHead = *( void ** )( buscaHead + PROX );   
        }
    }
    ListarDados ( pessoasEncontradas );
    free(pessoasEncontradas);
    */
}
/*
====================
RemoverDados
    REMOVE O DADO DE UMA PESSOA NO BUFFER
====================
*/
void *RemoverDados ( void *head, void *dadosPessoa ){
    
    if ( head == 0 ) {
        printf( "\n\tAgenda vazia\n" );
        return;
    }
    void *dadosParaRemover = dadosPessoa;
    //REMOVER O PRIMEIRO ELEMENTO
    if ( strcmp( ( char* )head , ( char * )dadosParaRemover ) == 0 ){ // compara o primeiro da head com o dado que eu quero remover
        if ( * (void **)(head + PROX) == NULL){
            head = NULL;
            printf( "\n\tDados removidos!\n" );
            return head;
        }
        void *novoHead = *( void ** )( head + PROX);
        *( void ** )( novoHead + PREV ) = NULL; // o prev da nova head recebe NULL
        free( head );
        printf( "\n\tDados removidos!\n" );
        return novoHead;
    }
    else {
        //PERCORRE O BUFFER
        void *novoHead = head;
        while ( *( void ** )( novoHead + PROX ) != NULL ) {
            if ( novoHead != NULL){
                //REMOVE NO MEIO
                if ( strcmp ( *( char ** )novoHead, *( char ** ) dadosParaRemover ) == 0 ){
                    void *nodoAnterior =  *( void ** )( novoHead + PREV );
                    void *nodoAFrente =  *( void ** )( novoHead + PROX );
                    * ( void ** )( nodoAnterior + PROX ) = *( void ** )( novoHead + PROX );
                    * ( void ** )( nodoAFrente + PREV ) = nodoAnterior;
                    free( novoHead );
                    printf( "\n\tDados removidos!\n" );
                    return head;
                }
                novoHead = *( void ** )( novoHead + PROX );
            }
        }
        //REMOVER NO FIM
        if ( *( void ** )( novoHead + PROX ) == NULL && strcmp ( *(char ** )novoHead, *(char ** ) dadosParaRemover ) == 0 ){
            void *nodoAnterior =  *( void ** )( novoHead + PREV );
            *( void ** )( nodoAnterior + PROX ) = NULL;
            free( novoHead );
            printf( "\n\tDados removidos!\n" );
            return head;
        }
        else {
            printf( "\n\tDado não cadastrado na agenda. Tente novamente com outro dado!\n" );
            return head;
        }
    }
}
/*
====================
LimparLista
    DESALOCA A MEMORIA USADA NA LISTA DO BUFFER 
====================
*/
void *LimparLista( void *head ){
    if ( head == 0 ) {
        printf( "\n\tAgenda vazia\n" );
        return head;
    }
    void *proxHead;
    while ( * ( void **)( head + PROX ) != NULL){
        proxHead = *( void ** )( head + PROX);
        free(* ( void **)(head + PREV ) );
        head = proxHead;
    }
    printf("\n\tLista limpa!\n");
}