/*Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
Não pode usar struct em todo o programa.
Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
Implementar a base de dados da agenda usando lista duplamente ligada
Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
Seguir as orientações elaborados pelo monitor para código!
Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.
Vou perguntar no 1:1 sobre a sua implementação. Posso pedir para fazer alguma modificação no código na nossa conversa*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Menu ( void );
void IncluirDados( void* pBuffer );
void ListarPessoas ( void* pBuffer );
void ApagarDados ( void** pBuffer);

int main (){

    int escolha;
    void *pBuffer = malloc (1);
    strcpy(pBuffer,"");

    for ( ;; ){
        escolha = Menu();
        switch ( escolha )
        {
        case 1:
            IncluirDados( pBuffer );
            break;
        
        case 2:
            ListarPessoas( pBuffer );
            break;
            
        case 3:
            ApagarDados ( &pBuffer );
            break;
            
        case 4:
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

   } while ( escolha <= 0 || escolha > 5 );
    getchar();
    return escolha;
}

void IncluirDados( void* pBuffer ){

    char nome[ 11 ], idadeString [ 2 ], telefoneString [ 9 ];
    int idade, telefone;
    printf( "Digite um nome: " );
    
    do{
        scanf("%10[^\n]s", nome);
        fflush(stdin);
    } while ( strlen ( nome ) > 10);
    
    pBuffer = realloc( pBuffer, sizeof( pBuffer ) + sizeof( nome ) + 3);
    if ( pBuffer == NULL ) {
        printf("Erro ao alocar memória\n");
        return;
    }
    strcat( pBuffer, nome );
    strcat( pBuffer, "." );


    printf( "Digite a idade de %s: ", nome);
    scanf( "%d", &idade );

    pBuffer = realloc( pBuffer, sizeof (pBuffer) + sizeof(int) + 1);

    sprintf (idadeString, "%d", idade); // transforma a variavel idade em uma string para poder concatenar com o buffer
    strcat( pBuffer, idadeString );
    strcat( pBuffer, "." );

    printf( "Digite o telefone de %s: ", nome);
    scanf( "%d", &telefone );

    pBuffer = realloc ( pBuffer, sizeof( pBuffer) + sizeof ( int ) + sizeof(telefone));
    sprintf (telefoneString, "%d", telefone);
    strcat( pBuffer, telefoneString );
    strcat( pBuffer, "," );

    
}

void ListarPessoas ( void* pBuffer ){

    printf( "Lista de pessoas: %s", pBuffer );
}

void ApagarDados ( void **pBuffer){

    char dados [ 10 ], *dadosNoBuffer, *copiaBuffer, *copiaBuffer2, *copiaParaPrintBuffer, *dadosDisponiveis, *novoBuffer = NULL, *dadosParaRemover = NULL;
    int tamanhoDado = 0, tamanhoBuffer = 0;

    copiaBuffer = ( char * ) malloc ( strlen ( *pBuffer ) + 1); // cria copia do pBuffer para poder manipular os valores do pBuffer
    strcpy( copiaBuffer, *pBuffer );
    copiaBuffer2 = (char*)malloc(strlen(*pBuffer) + 1);
    strcpy( copiaBuffer2, *pBuffer);
    copiaParaPrintBuffer = (char*)malloc(strlen(*pBuffer) + 1);
    strcpy( copiaParaPrintBuffer, *pBuffer);

    
    dadosDisponiveis = strtok (copiaParaPrintBuffer, ",");
    
    printf("\nDados disponiveis: \n");
    while (dadosDisponiveis != NULL) { // enquanto a variável nao for vazia ela vai ficar imprimindo os tokens
        printf("Nomes: %s\n", dadosDisponiveis);
        dadosDisponiveis = strtok(NULL, ","); // estou passando NULL por que eu quero continuar vendo a mesma string
    }
    printf( "Apagar Dados (nome.idade.telefone): " );
    gets( dados );
    
    dadosNoBuffer = strtok( copiaBuffer, "," ); // Separa os nomes no buffer em tokens e armazena eles na variável
    while ( dadosNoBuffer != NULL ) 
    {
        if ( strcmp( dados, dadosNoBuffer ) == 0 ){
            dadosParaRemover = dadosNoBuffer;
            tamanhoDado = strlen( dadosParaRemover );
            tamanhoBuffer += tamanhoDado + 1; //tamanho do nome + o tamanho da virgula
        } else {
            tamanhoBuffer += strlen( dadosNoBuffer ) + 1;
        }
        dadosNoBuffer = strtok( NULL, "," ); 
    }

    if (dadosParaRemover != NULL){ // enquanto o nome a ser removido for diferente de nulo, ou seja, eu achei o nome que eu quero remover

        novoBuffer = ( char * ) malloc( tamanhoBuffer - tamanhoDado );
        novoBuffer[0] = '\0';

        dadosNoBuffer = strtok( copiaBuffer2, ",");
        while ( dadosNoBuffer != NULL )
        {
            if ( strcmp( dadosParaRemover, dadosNoBuffer ) != 0 ){ // enquanto a comparação der diferente de 0 quer dizer que o nome a ser removido ainda não foi achado no buffer
                strcat( novoBuffer, dadosNoBuffer );
                strcat( novoBuffer, ",");
            }
            dadosNoBuffer = strtok( NULL, "," );
        }
        free(*pBuffer);
        *pBuffer = ( void *) malloc( strlen( novoBuffer ) + 1 );
        strcpy( *pBuffer, novoBuffer);
        
    }
    free(novoBuffer);
}