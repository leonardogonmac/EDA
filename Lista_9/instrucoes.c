#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B) 
#define swap(A,B) Item t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A.num, B.num)){swap(A, B);}

typedef struct{
    int num;
    char nome[16];
}Item;

void insertionsort(Item* v, int l, int r){
    for(int i = r; i > l; i--){
        cmp_swap(v[i], v[i - 1]);
    }


    for(int i = l + 2; i <= r; i++){
        Item aux = v[i];
        int j = i;

        while(less(aux.num, v[j - 1].num)){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }


}

char* busca_bin(Item* v, int l, int r, int num){
    if(r < l){
        return NULL;
    }
    
    int meio = (r + l)/2;

    if(less(num, v[meio].num)){
        return busca_bin(v, l, meio - 1, num);
    }
    else if(less(v[meio].num, num)){
        return busca_bin(v, meio + 1, r, num);
    }
    else{
        return v[meio].nome;
    }

}

int main(void){
    int n, instrucao;
    char* res;
    scanf("%d", &n);
    
    Item* v = malloc(sizeof(Item)*n);

    for(int i = 0; i < n; i++){
        scanf("%d %s", &v[i].num, v[i].nome);
    }

    insertionsort(v, 0, n - 1);

    while(scanf("%d", &instrucao) != EOF){
        res = busca_bin(v, 0, n - 1, instrucao);
        
        if(res == NULL){
            printf("undefined\n");
        }
        else{
            printf("%s\n", res);
        }
    }

    return 0;
}