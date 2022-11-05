#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int x;
    int soma = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        soma += x;
    }

    printf("%d\n", soma);

    return 0;

}