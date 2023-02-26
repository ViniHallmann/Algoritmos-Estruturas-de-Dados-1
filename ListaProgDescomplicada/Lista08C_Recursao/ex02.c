#include <stdio.h>
int Fatorial( int n );

int main (){
    int n;
    printf( "Digite um numero para saber o seu fatorial: " );
    scanf("%d", &n);
    printf("Fatorial de %d: %d", n, Fatorial(n));
}

int Fatorial( int n ){

    if (n == 0)
        return 1;
    else return n*Fatorial(n-1);

}   