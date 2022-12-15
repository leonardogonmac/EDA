#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B) 
#define swap(A,B) int t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}

void insertionsort(int* v, int l, int r){
    for(int i = r; i > l; i--){
        cmp_swap(v[i], v[i - 1]);

    }


    for(int i = l + 2; i <= r; i++){
        int aux = v[i];
        int j = i;

        while(less(aux, v[j - 1])){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }


}

int main(void){
    int* v;
    int i = 0;
    v = malloc(sizeof(int)*50000);

    while(scanf("%d", &v[i]) != EOF){
        i++;
    }

    insertionsort(v, 0, i - 1);

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);

    }
    printf("\n");

    return 0;
}