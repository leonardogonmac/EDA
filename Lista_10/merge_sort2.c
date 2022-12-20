#include <stdio.h>
#include <stdlib.h>

void merge2(int* v, int l1, int r1, int l2, int r2){
    int* v1 = malloc(sizeof(int)*((r1 - l1 + 1)));
    int* v2 = malloc(sizeof(int)*((r2 - l2 + 1)));
    int j = 0;

    for(int i = l1; i <= r1; i++){
        v1[j++] = v[i];
    }

    j = 0;

    for(int i = l2; i <= r2; i++){
        v2[j++] = v[i];
    }
    
    int i1 = 0, i2 = 0, i_v = l1;
    
    while(i1 <= (r1 - l1) && i2 <= (r2 - l2)){
        if(v1[i1] <= v2[i2]){
            v[i_v++] = v1[i1++];
        }
        else{
            v[i_v++] = v2[i2++];
        }
    }

    while(i1 <= (r1 - l1)){
        v[i_v++] = v1[i1++];
    }

    while(i2 <= (r2 - l2)){
        v[i_v++] = v2[i2++];
    }

}

void mergesort(int* v, int l, int r){
    if(l == r){
        return;
    }
    int meio = (l + r)/2; 

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);

    merge2(v, l, meio, meio + 1, r);

}

int main(void){
    int* v = malloc(sizeof(int)*100000);
    int i = 0;

    while(scanf("%d", &v[i]) != EOF){
        i++;
    }

    mergesort(v, 0, i - 1);

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);
    }
    printf("\n");

    return 0;
}