#include <stdio.h>

int main(void){
    int t, n;

    while(scanf("%d %d", &t, &n) != EOF){
        if(t == 0){
            break;
        }

        char nomes[t][11];
        int pontos[t];
        int sum = 0;
        
        for(int i = 0; i < t; i++){
            scanf(" %s %d", nomes[i], &pontos[i]);
            sum += pontos[i];
        }

        int empates = n*3 - sum;
        printf("%d\n", empates);


    }

    return 0;
}