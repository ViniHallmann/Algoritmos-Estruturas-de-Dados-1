/*Uma palavra de Fibonacci e definida por 
f(n) = b se n = 0
f(n) = a se n = 1
f(n) = f(n-1)+f(n-2) se n > 1
3
Aqui o sımbolo “+” denota a concatenac¸ao de duas strings. Esta sequencia inicia com as seguintes palavras:
b, a, ab, aba, abaab, abaababa, abaababaabaab, ...
Faca uma funcao recursiva que receba um numero N e retorne a N-esima palavra de Fibonacci.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *PalavraFibonacci( int n );

int main (){
    int n;
    printf( "Digite um numero N: " );
    scanf( "%d", &n );

    char *palavra = PalavraFibonacci(n);
    printf("%s", palavra);
    free(palavra); // Libera a memória alocada
}

char *PalavraFibonacci( int n ){    

    char *palavra = malloc(sizeof(char) * 100), *aux1, *aux2; 
    /*
    Aloco dinamicamente a memoria para char *palavra. Quando a função termina, a memória que foi alocada para a variável palavra é liberada, 
    o que faz com que o ponteiro retornado pela função aponte para uma área de memória inválida, por isso e necessario a alocacao.
    */

    if (n == 0) {
        strcpy( palavra, "b" ); // Copio "b" para a palavra
        return palavra;
    } else if (n == 1) {
        strcpy( palavra, "a" ); // Copio o "a" para a palavra
        return palavra; 
    } else {
        aux1 = PalavraFibonacci(n-1); // variaveis auxiliares que fazem a recursao 
        aux2 = PalavraFibonacci(n-2);
        strcpy(palavra, aux1); // aqui eu preciso usar cpy primeiro pois se nao sempre iria aparecer b na frente de qualquer N numeros de sequencia, o que e errado.
        strcat(palavra, aux2);
        return palavra;
    }             
}

/*
Demorei para fazer esse codigo e precisei da ajuda do ChatGPT, pois eu nao tinha percebido que precisava alocar a memoria do char *Palavra.
Agora eu entendi que quando eu fizer  alguma recurssao que use uma variavel local da funcao, e preciso alocar ela para que ela nao seja "liberada"
Este era meu codigo antes: 

#include <stdio.h>
#include <string.h>

char PalavraFibonacci( int n );

int main (){
    int n;
    printf( "Digite um numero N: " );
    scanf( "%d", &n );
    printf( "%c", PalavraFibonacci( n ) );
}

char PalavraFibonacci( int n ){    

    char palavra[100], aux1, aux2;     

    if (n == 0) {
        strcat( palavra, "b" );
        return *palavra;
    } else if (n == 1) {
        strcat( palavra, "a" );
        return *palavra; 
    } else {
        aux1 = PalavraFibonacci(n-1);
        aux2 = PalavraFibonacci(n-2);
        strcat( palavra, aux1);
        strcat( palavra, aux2)
        return palavra;
    }     

*/
