#include <stdio.h>

#define less(A, B) (A < B) 
#define swap(A,B) int t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}

void selectionsort(int* v, int l, int r){
    for(int i = l; i < r; i++){
        for(int j = i; j <= r; j++){
            cmp_swap(v[j], v[i]);
        }
    }

}

int main(void){
    int v[1000];
    int i = 0;

    while(scanf("%d", &v[i]) != EOF){
        i++;

    }
    printf("\n");

    selectionsort(v, 0, i - 1);

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);

    }
    printf("\n");


    return 0;
}