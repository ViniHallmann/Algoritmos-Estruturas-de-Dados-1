/*. Elabore uma funcao que receba duas strings como parametros e verifique se a segunda
string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres 
das strings.*/

#include <stdio.h>
#include <string.h>

void funcao (char *string1, char *string2);

int main(){
    char string1[] = "Teto branco", string2[] = "branco";
    funcao (string1, string2);
}

void funcao (char *string1, char *string2){
    char *resultado;

    resultado = strstr(string1, string2);
    if (resultado != NULL){
        printf("A segunda string esta contida na primeira");
    } else {
        printf("A segunda string nao esta contida na primeira");
    }
}

/*int funcao (char string1[], char string2[]){

    int i;

    for ( i = 0; i < strlen(string1) - strlen(string2); i++){
        int j;
        for (j = 0; j < strlen(string2); j++){
            if (string1[i] != string2[j])
                break;
        }

        if (j == strlen(string2))
            return 1;
    }
    
}*/