#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int contador = 0;

    while(scanf("%d", &n) > 0){
        contador++;
    }

    printf("%d\n", contador);
    
    return 0;
}