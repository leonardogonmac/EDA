#include <stdio.h>

int conta_pares(char* string){
    if(*(string + 2) == '\0'){
        return 0;
    }
    else if(*string == *(string + 2)){
        return 1 + conta_pares(string + 1);
    }
    else{
        return conta_pares(string + 1);
    }

}

int main(void){
    char string[201];
    int qtde_pares;
    
    scanf(" %s", string);
    qtde_pares = conta_pares(string);    
    printf("%d\n", qtde_pares);

    return 0;
}