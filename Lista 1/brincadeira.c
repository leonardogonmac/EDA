#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int r;
    int p = 0;
    int x[10000];
    int y[10000];

    scanf("%d", &n);

    while(n != 0){
        x[p] = n;
        y[p] = 0;

        for(int i = 0; i < n; i++){
            scanf("%d ", &r);
            y[p] += r;
            x[p] -= r;
        }

        p++;
        scanf("%d", &n);
    }

        for(int i = 0; i < p; i++){
            printf("Alice ganhou %d e Beto ganhou %d\n", x[i], y[i]);
        }
    return 0;

}