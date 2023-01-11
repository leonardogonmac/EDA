#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int n_vector[100];
    int j;
    int z;
    int res[100][100];
    int pos_n = 0;
    scanf("%d", &n);
    n_vector[pos_n] = n;

    while(n > 0){

        for(int i = 0; i < n; i++){
            scanf("%d %d", &j, &z);
            if(i == 0){
                res[pos_n][i] = (j - z);
            }
            if(i > 0){
                res[pos_n][i] = res[pos_n][i - 1] + (j - z);
            }

        }
        pos_n++;
        scanf("%d", &n);
        n_vector[pos_n] = n;

    }

    for(int i = 0; i < pos_n; i++){
        printf("Teste %d\n", (i + 1));
        for(int j = 0; j < n_vector[i]; j++){
            printf("%d\n", res[i][j]);
        }
        printf("\n");

    }

    return 0;

}