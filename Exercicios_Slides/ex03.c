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

int main (){

    int escolha;
    void *pBuffer = malloc(sizeof(void));

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

    char nome[ 10 ], idadeString [2];
    int idade;
    printf( "Digite um nome: " );
    gets ( nome );
    pBuffer = realloc( pBuffer, sizeof( pBuffer ) + sizeof( nome ) + 2);
    strcat( pBuffer, nome );
    strcat( pBuffer, "." );


    printf( "Digite a idade de %s: ", nome);
    scanf( "%d", &idade );

    pBuffer = realloc( pBuffer, sizeof (pBuffer) + sizeof(int) + 2);

    sprintf (idadeString, "%d", idade);
    strcat( pBuffer, idadeString );
    strcat( pBuffer, ",\n" );
}

void ListarPessoas ( void* pBuffer ){

    printf( "\n\tLista de pessoas:\n %s", pBuffer );
}
