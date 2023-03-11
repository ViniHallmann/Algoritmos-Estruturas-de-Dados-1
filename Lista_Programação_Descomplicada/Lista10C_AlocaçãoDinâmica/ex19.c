/*Faca um programa para associar nomes as linhas de uma matriz de caracteres. O usuario ira informar o numero maximo de nomes que poderao ser armazenados. 
Cada nome podera ter ate 30 caracteres com o ’\0’. O usuario podera usar 5 opcoes diferentes para manipular a matriz:
(a) Gravar um nome em uma linha da matriz;
(b) Apagar o nome contido em uma linha da matriz;
(c) Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome;
(d) Informar um nome, procurar a linha onde ele se encontra e apagar;
(e) Pedir para recuperar o nome contido em uma linha da matriz;*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ReadString(char string[30]);
int Menu(void);
char **PutNameMatriz(char **matriz, int totalNames);
void PrintNamesMatriz(char **matriz, int totalNames);
void PrintNameLine(char **matriz, int totalNames, int line);
char **RemoveNameMatriz(char**matriz, int line);
char **ReplaceNameMatriz(char**matriz);
char **RemoveNameLineMatriz(char**matriz, int totalNames);

int main (){

    char **matriz, *nameToReplace;

    int totalNames, line;
    printf("Digite o total de nomes: ");
    scanf("%d", &totalNames);
    getchar();
    
    matriz = (char **) malloc ( totalNames * sizeof ( char *) );

    for (int i = 0; i < totalNames; i++){
        matriz[i] = (char *) malloc( 30 * sizeof ( char ) );
    }
    for(;;){
        int escolha = Menu();
        switch (escolha) 
        {
            case 1:
                matriz = PutNameMatriz(matriz, totalNames);
                break;
            case 2:
                PrintNamesMatriz(matriz, totalNames);
                break;
            case 3:
                printf("Digite a linha do nome que deseja remover: ");
                scanf("%d", &line);
                getchar();
                matriz = RemoveNameMatriz(matriz, line);
                break;
            case 4:
                matriz = ReplaceNameMatriz(matriz);
                break;
            case 5:
                matriz = RemoveNameLineMatriz(matriz, totalNames);
                break;
            case 6:
                printf("Digite a linha do nome que deseja vizualizar: ");
                scanf("%d", &line);
                getchar();
                PrintNameLine(matriz, totalNames, line);
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }
    }
    

}

int Menu(){
    int escolha;

    do{
        printf("\tMenu\n");
        printf("(1) Gravar um nome em uma linha da matriz\n");
        printf("(2) Mostrar todos os nomes da matriz\n");
        printf("(3) Apagar o nome contido em uma linha da matriz\n");
        printf("(4) Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome\n");
        printf("(5) Informar um nome, procurar a linha onde ele se encontra e apagar\n");
        printf("(6) Pedir para recuperar o nome contido em uma linha da matriz\n");
        printf("(7) Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        system("cls");
        getchar();
    }while ( escolha <= 0 || escolha > 7 );
    
    return escolha;

}

int lastUsedLine = 0; 

char **PutNameMatriz(char **matriz, int totalNames){
    if (lastUsedLine == totalNames){
        printf("\n\n\tA matriz esta cheia!\n\n");
        return matriz;
    }
        
    printf("Digite o nome: ");
    ReadString (matriz[lastUsedLine]);
    lastUsedLine++;
    system("cls");
    return matriz;

}
void PrintNamesMatriz(char **matriz, int totalNames){
    for(int i = 0; i < lastUsedLine; i++){
        printf("Linha %d Nome: %s\n",i , matriz[i]);
    }
}

char **RemoveNameMatriz(char**matriz, int line){

    matriz[line][0] = '\0';

    if (line == lastUsedLine)
        lastUsedLine--;
    
    return matriz;
}
char **ReplaceNameMatriz(char**matriz){

    char *newName = (char *) malloc(30 * sizeof(char));
    char *nameToReplace = (char *) malloc(30 * sizeof(char));
    
    printf("Digite o nome que deseja substituir: ");
    ReadString(nameToReplace);

    for (int i = 0; i < lastUsedLine; i++){
        if (strcmp(matriz[i], nameToReplace) == 0){
            printf("Digite o novo nome: ");
            ReadString(newName);
            strcpy(matriz[i], newName);
            break;
        }
    }
    return matriz;
}

char **RemoveNameLineMatriz(char**matriz, int totalNames){

    char *nameToRemove = (char *) malloc(30 * sizeof(char));
    int i;
    printf("Digite o nome que deseja apagar: ");
    ReadString(nameToRemove);

    for (i = 0; i < totalNames; i++){
        if (strcmp(matriz[i], nameToRemove) == 0){
            matriz[i] = '\0';
            break;
        }
    }
    if (lastUsedLine == i)
        lastUsedLine--;
    return matriz;
}

void PrintNameLine(char **matriz, int totalNames, int line){
    for (int i = 0; i < totalNames; i++){
            if(i == line){
                printf("\nNome: %s\n", matriz[i]);
                break;
            } else {
                printf( "Nome não encontrado...\n" );
                break;
            }
    }
}

void ReadString(char string[30]){
    char c;
    int i = 0;
    while((c = getchar()) != '\n'){
        string[i] = c;
        i++;
    }
    string[i] = '\0';
}