/*Lista 2 - Exercício 3
• Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
• Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
• Cada pessoa tem nome[10], idade e telefone.
• O trabalho que vale nota será uma continuação deste.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Menu ( void );
void IncluirDados( void* pBuffer );
void ListarPessoas ( void* pBuffer );
void ApagarDados ( void *pBuffer);

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
            ApagarDados ( pBuffer );
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

    char nome[ 10 ], idadeString [ 2 ], telefoneString [ 9 ];
    int idade, telefone;
    printf( "Digite um nome: " );
    //fgets ( nome, 10, stdin);
    //getchar();
    //gets ( nome );
    scanf("%[^\n]s", nome);
    
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

void ApagarDados ( void *pBuffer){
    char nome [ 10 ], *nomesNoBuffer;

    printf( "Digite o nome de quem deseja apagar os dados: " );
    gets( nome );

    nomesNoBuffer = strtok( pBuffer, "," ); // Separa os nomes no buffer em tokens e armazena eles na variável
    
    while ( nomesNoBuffer != NULL ) // enquanto a variável nao for vazia ela vai ficar imprimindo os tokens
    {
        printf( "Nomes: %s\n", nomesNoBuffer ); 
        nomesNoBuffer = strtok( NULL, "," ); // Estou passando NULL por que eu quero continuar vendo a mesma string
    }
    /*if (strcmp(nome, nomesSeparados) == 0){
            nomeASerRemovido = nomesSeparados;
            tamanhoNome = strlen(nomeASerRemovido);
            *listaDeNomes = (char*) realloc(*listaDeNomes, strlen(*listaDeNomes) - tamanhoNome);
        }*/
    // Preciso fazer uma função que percorre o buffer, depois que encontrar o nome realocar o valor novo pro buffer 
}
