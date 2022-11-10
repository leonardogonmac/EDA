#include <stdio.h>

int main(void){
    int n;
    int value;
    int sum = 0;
    int ans;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        sum += value;
    }
    scanf("%d", &ans);

    if(ans == sum){
        printf("Acertou\n");
    }
    else{
        printf("Errou\n");
    }

    return 0;
}