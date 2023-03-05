/*Faça um programa que armazene a informação de várias pessoas.
•O programa só deve sair quando o usuário disser que não deseja mais entrar com os dados de outra pessoa.
•Antes de sair o programa deve apresentar, de forma organizada, os dados de todas as pessoas.*/
#include <stdio.h>
#include <Stdlib.h>

struct pessoa {
    char name[30];
    int age;
    int CPF;
    struct pessoa *next;
}; typedef struct pessoa pessoa;

pessoa *CreateList();
void Insert (pessoa *plist);
void ReadString(char name[30]);
void PrintList(pessoa *plist);

int main(){
    int nBreak;
    pessoa *list;

    list = CreateList();

    for(;;){
        Insert ( list );
        printf("Continuar? (1 - Sim)/(0 - Nao): ");
        scanf("%d", &nBreak);
        if (nBreak == 0){
            PrintList( list );
            break;
        }
    }
    
}

pessoa *CreateList(){
    pessoa *inicio;
    inicio = ( pessoa * ) malloc ( sizeof ( pessoa ) );
    inicio -> next = NULL;
    return inicio;
}

void Insert (pessoa *plist){

    pessoa *new, *end;

    for (end = plist; end -> next != NULL; end = end -> next);
    new = (pessoa *) malloc (sizeof ( pessoa ) );
    new -> next = end -> next;
    end -> next = new;

    printf("Digite o nome: ");
    ReadString(new -> name);
    printf("Digite a idade de %s: ", new -> name);
    scanf("%d", &new -> age);
    printf("Digite o CPF: ");
    scanf("%d", &new -> CPF);


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

void PrintList(pessoa *plist){
    pessoa *printPessoa;

    for( printPessoa = plist -> next; printPessoa != NULL; printPessoa = printPessoa -> next){
        printf("%s %d %d", printPessoa -> name, printPessoa -> age, printPessoa -> CPF);

    }
}