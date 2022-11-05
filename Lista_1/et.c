#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char string[30];
    int acertou = 0;

    while(scanf("%s", &string) != EOF){
        if(strcmp(string, "marte") == 0){
            acertou++;
        }
    }
    
    if (acertou != 0){
        printf("Leonardo Cicero Marciano\n");
    }
    else{
        printf("none\n");
    }
    
   

    return 0;
}