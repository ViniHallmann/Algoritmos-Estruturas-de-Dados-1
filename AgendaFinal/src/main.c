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
void *pegarDados   ();
void *incluirDados ( void *head, void *dadosPessoa );
void *removerDados ( void *head, void *dadosPessoa );
void listarDados   ( void *head );
void buscarDados   ( void *head );
void menu          ( void *head );


// Funções
int main (){
    void *head = malloc( 0 );
    head = 0;
    menu( head );
}

void menu ( void *head ){
    for ( ; ; ){
        printf( "\n\t\tMENU\n" );
        printf( "\t1)Incluir nome;\n" );
        printf( "\t2)Listar pessoas;\n" );
        printf( "\t3)Buscar pessoa;\n" );
        printf( "\t4)Remover dados\n" );
        printf( "\t5)Sair.\n" );
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
            buscarDados( head );
            getchar();
            break;
        case '4': 
            head = removerDados ( head, pegarDados() );
            getchar();
            break;
        case '5': 
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

    return pessoa;
}

void *incluirDados ( void *head, void *dadosPessoa ){
    //INSERIR NO INICIO
    if ( head == 0 ){   
        head = dadosPessoa;
        *(void ** )( head + PREV ) = NULL;
        *(void ** )( head + PROX ) = NULL;
        return head;
    } 
    //INSERIR NO INICIO SE O PRIMEIRO VALOR DO HEAD FOR MAIOR QUE O pPESSOA
    if ( strcmp ( ( char * )head ,  ( char * )dadosPessoa ) > 0 ){
        void *novoHead = dadosPessoa;
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
                novoHead = *( void ** )( novoHead + PROX );
                //INSERIR NO MEIO
                if (  strcmp ( ( char* ) novoHead, ( char* ) dadosPessoa ) > 0){
                    void *tempPREV = *(void **)(novoHead + PREV);
                    void *tempPROX = novoHead;
                    *( void ** )( dadosPessoa + PREV ) = tempPREV;
                    *( void ** )( dadosPessoa + PROX ) = novoHead;
                    *( void ** )( tempPROX + PREV) = dadosPessoa;
                    *( void ** )( tempPREV + PROX ) = dadosPessoa;
                    return head;
                }
            }
        }
        //INSERIR NO FINAL
        *( void ** )( dadosPessoa + PREV ) = novoHead;
        *( void ** )( novoHead + PROX ) = dadosPessoa;
        *( void ** )( dadosPessoa + PROX ) = NULL;
        return head;
    }
}

void listarDados ( void *head ){
    //LISTA OS DADOS DA LISTA
    if ( head == 0 ) {
        printf("\n\tAgenda vazia\n");
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

void buscarDados ( void *head ){
    void *buscaHead = head;
    void *pPessoa = malloc ( NOME_SIZE );

    printf( "\tDigite o nome: " );
    scanf( "%s", ( char * )pPessoa );

    if ( head == 0 ) {
        printf("\n\tAgenda vazia\n");
        return;
    } 
    while ( *( void ** )buscaHead  != NULL ){
        if ( buscaHead != NULL){
            if ( strcmp ( ( char* ) buscaHead, ( char* ) pPessoa ) == 0 ){
                printf("\n\t'%s' está na agenda. O telefone de %s é: %d\n", ( char * )buscaHead, ( char * )buscaHead, *( int * )( ( char * )buscaHead + TELEFONE_SIZE )  );
                break;
            }
            buscaHead = *( void ** )( buscaHead + PROX );
            // se o nome nao estiver na agenda eu posso chamar a funcao incluir dados aqui? so uma ideia.   
        }
    }
}

void *removerDados ( void *head, void *dadosPessoa ){
    void *dadosParaRemover = dadosPessoa;
    //REMOVER O PRIMEIRO ELEMENTO
    if ( strcmp( ( char* )head , ( char * )dadosParaRemover ) == 0){
        void *novoHead = *(void**)( head + PROX );
        *( void ** )( novoHead + PREV ) = NULL;
        free( head );
        printf( "\n\tDados removidos!\n" );
        return novoHead;
    }
    else {
        //PERCORRE O pBUFFER
        void *novoHead = head;
        while ( *( void ** )( novoHead + PROX ) != NULL ) {
            if ( novoHead != NULL){
                novoHead = *( void ** )( novoHead + PROX );
                if ( strcmp ( *( char ** )novoHead, *( char ** ) dadosParaRemover ) == 0 ){
                    void *nodoAnterior =  *( void ** )( novoHead + PREV );
                    void *nodoAFrente =  *( void ** )( novoHead + PROX );
                    * ( void ** )( nodoAnterior + PROX ) = *( void ** )( novoHead + PROX );
                    * ( void ** )( nodoAFrente + PREV ) = nodoAnterior;
                    free( novoHead );
                    printf( "\n\tDados removidos!\n" );
                    return head;
                }
            }
        }
        //REMOVER NO FIM
        if ( *( void ** )( novoHead + PROX) == NULL && strcmp ( *(char **)novoHead, *(char **) dadosParaRemover) == 0 ){
            void *nodoAnterior =  *( void ** )( novoHead + PREV );
            *( void ** )( nodoAnterior + PROX ) = NULL;
            free( novoHead );
            printf( "\n\tDados removidos!\n" );
            return head;
        }
        else {
            printf("\n\tDado não cadastrado na agenda. Tente novamente com outro dado!");
            return head;
        }
    }
}