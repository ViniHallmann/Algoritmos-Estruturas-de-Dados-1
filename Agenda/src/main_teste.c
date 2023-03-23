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
void IncluirDados( void **pBuffer );
void ListarPessoas ( void *pBuffer );
void ApagarDados ( void **pBuffer);

int main (){

    int escolha;
    void *pBuffer = NULL;

    for ( ;; ){
        escolha = Menu();
        switch ( escolha )
        {
        case 1:
            IncluirDados( &pBuffer );
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

void IncluirDados(void **pBuffer){

    char *copiaBuffer;
    char *pNome = ( char * ) malloc ( sizeof ( char ) * 11);
    char *pIdadeString = ( char * ) malloc ( sizeof ( char ) * 3);
    char *pTelefoneString = ( char * ) malloc ( sizeof ( char ) * 10);
    

    printf( "Digite um nome: " );
    do{
        scanf( "%10[^\n]s", pNome );
        fflush(stdin);
    } while ( strlen ( pNome ) > 10 );

    printf( "Digite a idade de %s: ", pNome );
    do{
        scanf( "%2[^\n]s", pIdadeString );
        fflush(stdin);
    } while ( strlen ( pIdadeString ) > 3 );

    printf( "Digite o telefone de %s: ", pNome );
    do{
        scanf( "%9[^\n]s", pTelefoneString );
        fflush(stdin);
    } while ( strlen ( pTelefoneString ) > 9 );

    
    if ( strlen ( (char *) *pBuffer ) == 0 ) { // Se for o primeiro valor aloca ele direto na primeira posição
        *pBuffer = realloc( *pBuffer, sizeof( *pBuffer ) + sizeof( pNome ) + sizeof( pIdadeString ) + sizeof( pTelefoneString ) + 3);
        strcat( ( char * ) *pBuffer, pNome );
        strcat ( ( char * ) *pBuffer + strlen( pNome ), "." );
        strcat( ( char * ) *pBuffer, pIdadeString );
        strcat ( ( char * ) *pBuffer + strlen( pIdadeString ), "." );
        strcat( ( char * ) *pBuffer, pTelefoneString );
        strcat ( ( char * ) *pBuffer + strlen( pTelefoneString ), "," );
    } else { // ESSA PARTE DO CODIGO SO FUNCIONA SE ESTIVER NO MEIO DA LISTA
            // PRECISO FAZER UM IF SE O DADO == NULL, ou seja, se estiver no final eu nao vou precisar usar o memmove...
        copiaBuffer = ( char * ) malloc ( strlen ( *pBuffer ) + 1); 
        strcpy( copiaBuffer, ( char * )*pBuffer ); // faco uma copia do pBuffer
        
        char *dados = strtok ( copiaBuffer, "," ); // quebro a copia em tokens
        char *posicao = (char *) malloc(strlen(*pBuffer) + 1);// vou usar essa posicao para achar o tamanho do dado
        while (dados != NULL){ // enquanto o dado token do dado for diferente de nulo ele continua a repeticao
            if ( strcmp( dados,  pNome) < 0 ){ // faz a comparacao para ver se o token dado e menor que o nome
                break;
            }
            posicao += strlen ( dados ) + 1; // vai somando o tamanho dos dados comparados
            dados = strtok ( NULL, "," ); // isso aqui serve para o strtok continuar ate chegar na ultima virgula do copiaBuffer
        } //Depois q terminar a repeticao eu aloco a memoria anterior do pBuffer + a nova memoria dele (nome, idade e telefone)
       
        *pBuffer = realloc( *pBuffer, strlen(*pBuffer) + sizeof( pNome ) + sizeof( pIdadeString ) + sizeof( pTelefoneString ) + 4);

        //Acho que meu problema esta aqui, eu preciso mover para frente a minha string 
        //tenho o meu destino como primeiro parametro o valor que aponta para o meu destino (que seria o meu valor mais o tamanho da posicao), 
        //o endereco de origem ( posicao ), 
        // o meu tamanho ( a diferenca entre o copiaBuffer e o posicao)
        memmove(posicao + strlen(pNome) + strlen(pIdadeString) + strlen(pTelefoneString) + 3,
        posicao, strlen(*pBuffer) - (posicao - (char*)*pBuffer) + strlen(pNome) + strlen(pIdadeString) + strlen(pTelefoneString) + 4);
        strncpy(( char * ) *pBuffer + *posicao, pNome, strlen(pNome) );
        strcat ( ( char * ) *pBuffer + strlen( pNome ) + *posicao, "." );
        strcat( ( char * ) *pBuffer + *posicao, pIdadeString );
        strcat ( ( char * ) *pBuffer + strlen( pIdadeString ) + *posicao , "." );
        strcat( ( char * ) *pBuffer + *posicao, pTelefoneString );
        strcat ( ( char * ) *pBuffer + strlen( pTelefoneString ) + *posicao, "," );

        /* jeito mais simples que o chat deu para concatenar os ponteiros
        char * tempBuffer;
        sprintf(*tempBuffer, "%s.%s.%s,", pNome, pIdadeString, pTelefoneString);
        int *tempBufferLen = (char*) malloc(sizeof(strlen(tempBuffer)));*/
        
    }
    free(pNome);
    free(pIdadeString);
    free(pTelefoneString);
}

void ListarPessoas ( void *pBuffer ){

    char *copiaBuffer = ( char * ) malloc ( strlen ( pBuffer ) + 1);
    strcpy( copiaBuffer, pBuffer );
    copiaBuffer = strtok ( copiaBuffer, "," );

    printf( "Lista de Pessoas e dados: \n" );
    while ( copiaBuffer != NULL ){
        printf ( "%s\n", copiaBuffer );
        copiaBuffer = strtok ( NULL, "," );
    }

    free(copiaBuffer);
}

void ApagarDados ( void **pBuffer){

    char *dados, *dadosNoBuffer, *copiaBuffer, *copiaBuffer2, *copiaParaPrintBuffer, *dadosDisponiveis, *novoBuffer = NULL, *dadosParaRemover = NULL;
    int *tamanhoDado, *tamanhoBuffer;

    dados = ( char * ) malloc ( sizeof ( char ) * 26);
    tamanhoDado = ( int *) malloc ( sizeof ( int ) );
    tamanhoBuffer = ( int *) malloc ( sizeof ( int ) );
    *tamanhoBuffer = 0;
    *tamanhoDado = 0;

    copiaBuffer = ( char * ) malloc ( strlen ( *pBuffer ) + 1); // cria copia do pBuffer para poder manipular os valores do pBuffer ( Quebra o buffer e armazena os dados )
    strcpy( copiaBuffer, *pBuffer );
    

    copiaBuffer2 = ( char * ) malloc( strlen ( *pBuffer ) + 1); // cria copia do pBuffer para poder manipular os valores do pBuffer ( Quebra o buffer e percorre os tokens para achar o dado a ser removido )
    strcpy( copiaBuffer2, *pBuffer );

    copiaParaPrintBuffer = ( char * ) malloc( strlen( *pBuffer ) + 1 );  // // cria copia do pBuffer para poder manipular os valores do pBuffer ( Quebra o buffer para mostrar os dados disponiveis um por vez ) 
    strcpy( copiaParaPrintBuffer, *pBuffer );
    dadosDisponiveis = strtok ( copiaParaPrintBuffer, "," );
    
    printf( "\nDados disponiveis: \n" );
    while ( dadosDisponiveis != NULL ) { // enquanto a variável nao for vazia ela vai ficar imprimindo os tokens
        printf( "Nomes: %s\n", dadosDisponiveis );
        dadosDisponiveis = strtok( NULL, "," ); // estou passando NULL por que eu quero continuar vendo a mesma string
    }

    printf( "Apagar Dados (nome.idade.telefone): " );
    gets( dados );
    
    dadosNoBuffer = strtok( copiaBuffer, "," ); // separa os nomes no buffer em tokens e armazena eles na variável
    while ( dadosNoBuffer != NULL ) 
    {
        if ( strcmp( dados, dadosNoBuffer ) == 0 ){
            dadosParaRemover = dadosNoBuffer;
            *tamanhoDado = strlen( dadosParaRemover );
            *tamanhoBuffer += *tamanhoDado  + 1; // tamanho do nome + o tamanho da virgula
        } else {
            *tamanhoBuffer += strlen( dadosNoBuffer ) + 1;
        }
        dadosNoBuffer = strtok( NULL, "," ); 
    }

    if (dadosParaRemover != NULL){ // enquanto o nome a ser removido for diferente de nulo, ou seja, eu achei o nome que eu quero remover

        novoBuffer = ( char * ) malloc( *tamanhoBuffer - *tamanhoDado );
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

        free(novoBuffer); //free(dados); free(dadosNoBuffer); free(copiaBuffer);free(copiaBuffer2);free(copiaParaPrintBuffer);free(dadosDisponiveis);free(dadosParaRemover); free(tamanhoDado);free(tamanhoBuffer);
    }
    
}
    
