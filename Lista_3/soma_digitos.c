#include <stdio.h>

void soma_digitos(char* n, int* ps){
    if(*n == '\0'){
        return;
    }
    else{
        *ps += *n - 48;
        soma_digitos(n + 1, ps);
    }
}

int main(void){
    char n[20];
    int s = 0;
    scanf(" %s", n);

    soma_digitos(n, &s);

    printf("%d\n", s);
    
    return 0;
}