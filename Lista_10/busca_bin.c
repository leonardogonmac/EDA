#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B) 
#define swap(A,B) int t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}



int busca_bin(int* v, int l, int r, int num){
    if(r < l || r == l){
        if(less(v[l], num)){
            return (l + 1);
        }
        else{
            return l;
        }
        
        return l;
    }
    
    
    int meio = (r + l)/2;

    if(less(num, v[meio])){
        return busca_bin(v, l, meio - 1, num);
    }
    else if(less(v[meio], num)){
        return busca_bin(v, meio + 1, r, num);
    }
    else{
        return meio;
    }

}

int main(void){
    int n, m, i, j, res;
    scanf("%d %d", &n, &m);

    int* v = malloc(sizeof(int)*n);
    int* busca = malloc(sizeof(int)*m);

    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(j = 0; j < m; j++){
        scanf("%d", &busca[j]);
    }

    for(int k = 0; k < j; k++){
        res = busca_bin(v, 0, i - 1, busca[k]);
        printf("%d\n", res);
    }

    return 0;
}