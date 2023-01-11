#include <stdio.h>

int main(void){
    int n[1000];
    char* letras = &n;
    int i = 0;
    int j = 0;
    
    while(scanf("%x", &n[i]) != EOF){
        i++;
    }

    while(letras[j] != 0){
        printf("%c", letras[j]);
        j++;
    }
    printf("\n");



    return 0;
}