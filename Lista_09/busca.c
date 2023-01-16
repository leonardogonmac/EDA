#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B) 
#define swap(A,B) Item t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}

typedef struct{
    int num;
    int pos;
}Item;

void insertionsort(Item* v, int l, int r){
    for(int i = r; i > l; i--){
        if(less_votos(v[i].num, v[i - 1].num)){
            Item t = v[i];
            v[i] = v[i - 1];
            v[i - 1] = t;
        }

    }


    for(int i = l + 2; i <= r; i++){
        Item aux = v[i];
        int j = i;

        while(less_votos(aux.num, v[j - 1].num)){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }


}

int busca_bin(Item* v, int l, int r, int num){
    if(r < l){
        return (-1);
    }
    
    int meio = (r + l)/2;

    if(less_votos(num, v[meio].num)){
        return busca_bin(v, l, meio - 1, num);
    }
    else if(less_votos(v[meio].num, num)){
        return busca_bin(v, meio + 1, r, num);
    }
    else{
        return v[meio].pos;
    }

}

int main(void){
    int n, m, res;
    Item* v;
    int* num_verificar;

    scanf("%d %d", &n, &m);

    v = malloc(sizeof(Item)*n);
    num_verificar = malloc(sizeof(int)*m);

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i].num);
        v[i].pos = i;
    }

    insertionsort(v, 0, n - 1);

    for(int i = 0; i < m; i++){
        scanf("%d", &num_verificar[i]);
    }
    printf("\n");

    for(int i = 0; i < m; i++){
        res = busca_bin(v, 0, n - 1, num_verificar[i]);
        printf("%d\n", res);
    }


    return 0;
}