#include <stdio.h>

#define less(A, B) (A < B) 
#define swap(A,B) int t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}

void bubblesort(int* v, int l, int r){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            cmp_swap(v[j + 1], v[j]);
        }

    }

}

int main(void){
    int vector[1000];
    int i = 0;

    while(scanf("%d", &vector[i]) != EOF){
        i++;
    }

    bubblesort(vector, 0, i - 1);
    
    for(int j = 0; j < i; j++){
        printf("%d ", vector[j]);
    }
    printf("\n");

    return 0;
}