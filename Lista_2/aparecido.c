#include <stdio.h>

int main(void){
    int n1, n2, n3, sum, ans;

    scanf("%d %d %d", &n1, &n2, &n3);
    scanf("%d", &ans);

    sum = (n1 + n2 + n3);

    if(ans == sum){
        printf("Acertou\n");
    }
    else{
        printf("Errou\n");
    }

    return 0;
}