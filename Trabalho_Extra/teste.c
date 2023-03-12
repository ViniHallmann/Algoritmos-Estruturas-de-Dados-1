#include <stdio.h>
#include <string.h>

int main(){
    char *str1 = {"a"}, *str2 = {"b"};
    printf("%d\n", strcmp(str1, str2)); // -1
    printf("%d", strcmp(str2, str1)); // 1
}