/*Faça um programa que armazena nomes. O programa deve armazenartodos os nomes na mesma string
O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos. Não pode ter desperdício de memória.

Faça o seguinte menu:
1) Adicionar nome
2) Remover nome
3) Listar
4) Sair

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu ( void );
void LerString();
void AdicionarNome ( char** listaDeNomes );
void RemoverNome ( char** listaDeNomes );
void ListarNome ( char* listaDeNomes );


int main(){

    int escolha;
    char *listaDeNomes = ( char* ) malloc ( sizeof ( char ) );
    
    for(;;){
        escolha = Menu();
        switch (escolha)
        {
        case 1:
            AdicionarNome( &listaDeNomes );
            break;
            
        case 2:
            RemoverNome( &listaDeNomes);
            break;
            
        case 3:
            ListarNome( listaDeNomes );
            break;
            
        case 4:
            exit(0);
            break;
            
        default:
            printf("ERRO KRL");
            break;
        }
    }

}

int Menu ( void ){

    int escolha;

   do {
        printf("\n\t\tMENU\n");
        printf( "\t1)Adicionar nome;\n" );
        printf( "\t2)Remover nome;\n" );
        printf( "\t3)Listar;\n" );
        printf( "\t4)Sair.\n" );
        printf( "\tDigite sua escolha: " );
        scanf("%d", &escolha);

   } while ( escolha <= 0 || escolha > 5 );
    getchar();
    return escolha;

}

void AdicionarNome ( char** listaDeNomes ){

    int tamanhoPalavra, tamanhoNovo;
    char nome[100];

    printf( "\tDigite o nome:" );
    scanf( "%s", nome );

    tamanhoPalavra = strlen(nome);
    tamanhoNovo = tamanhoPalavra + strlen ( *listaDeNomes );

    *listaDeNomes = ( char* ) realloc ( *listaDeNomes, tamanhoNovo + 1 );

    strcat(*listaDeNomes, nome);
    strcat(*listaDeNomes, ",");
    

}

void RemoverNome ( char** listaDeNomes ){

    char *nomesSeparados, nome[100], nomeASerRemovido[100];
    int c, tamanhoNome;

    printf( "Digite um nome para remover: " );
    scanf( "%s", nome );

    nomesSeparados = strtok( *listaDeNomes, "," );
    
    while ( nomesSeparados != NULL )
    {
        printf( "Nomes: %s\n", nomesSeparados ); 
        nomesSeparados = strtok( NULL, "," );
    }
    /*if (strcmp(nome, nomesSeparados) == 0){
            nomeASerRemovido = nomesSeparados;
            tamanhoNome = strlen(nomeASerRemovido);
            *listaDeNomes = (char*) realloc(*listaDeNomes, strlen(*listaDeNomes) - tamanhoNome);
        }*/

}

void ListarNome ( char* listaDeNomes ){
    printf("Nomes: %s", listaDeNomes);
}
