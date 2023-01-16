#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B) 

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

int busca_bin(int* v, int l, int r, int num){
    if(r < l){
        return (-1);
    }
    
    int meio = (r + l)/2;

    if(less_votos(num, v[meio])){
        return busca_bin(v, l, meio - 1, num);
    }
    else if(less_votos(v[meio], num)){
        return busca_bin(v, meio + 1, r, num);
    }
    else{
        return meio;
    }

}

int main(void){
    int n, num, res;
    scanf("%d", &n);

    int* v = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, n - 1);//ordena o vetor

    while(scanf("%d", &num) != EOF){
        res = busca_bin(v, 0, n - 1, num);
        if(res < 0){
            printf("nao\n");
        }
        else{
            printf("sim\n");
        }
    }


    return 0;
}