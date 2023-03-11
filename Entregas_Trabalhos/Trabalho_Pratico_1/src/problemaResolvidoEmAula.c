#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int JeitosDeSubir(int n);

int main(int argc, char const *argv[])
{
    int n, i, v[44], c = 0, resp;

    printf( "Digite o número de escadas: " );

    do
    {
        scanf( "%d", &n );
    } while (n <= 0 || n > 45);

    resp = JeitosDeSubir(n);
    printf("%d", resp);
    
    return 0;
}

int JeitosDeSubir(int n){

    if ( n <= 2 ) return n;
    return JeitosDeSubir(n-1)+JeitosDeSubir(n+2);

}   
    /*
    3        3-1 + 3-2 = 3
    1 1 1
    1 2
    2 1



    4 = 5    4-1 + 4-2 = 5                                   
    1 1 1 1
    1 1 2 
    1 2 1
    2 2
    2 1 1
    
    

    5 = 8     5-1 + 5-2    = 7 
    1 1 1 1 1
    1 1 1 2
    1 1 2 1
    1 2 1 1
    1 2 2

    2 1 1 1
    2 2 1
    2 1 2
    
    6  = 8    6-1 + 6-2 = 9        
    1 1 1 1 1 1
    1 1 1 1 2
    1 1 2 2
    1 1 1 2 1
    1 1 2 1 1

    1 2 1 1 1
    2 1 1 1 1
    2 2 1 1
    2 2 2

    for ( i = 0; i < n; i++ ){
        v[i] = 1; 
    }
    for ( i = 0; i < n; i++ ){
        printf("%d ", v[i]); 
    }
    for( i = 0; i < n; i++ ){
        if( v[i] == v[i+1] ){
            c++;
        }
    }*/

    

