#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int m;
    char l;
}Bota;

#define less(A, B) (A < B)
#define swap(A, B) Bota t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A.m, B.m)){swap(A, B)}

int separa(Bota* v, int l, int r){
    if(l >= r) return r;
    Bota p = v[r];
    int i = l - 1, j = r;
  
    for(;;){
        while(p.m > v[++i].m);
        while(p.m < v[--j].m) if(j == l) break;

        if(i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[r], v[i]);
    return i;

}

void quicksort(Bota* v, int l, int r){
    if(l >= r) return;
 
    swap(v[r - 1], v[(l + r)/2]); //v[r - 1] = meio
    //jogar o menor dos 3 em left
    cmp_swap(v[r], v[l]);  // se meio < left, meio vai pra left
    cmp_swap(v[r - 1], v[l]); //se right < (left ou meio), right vai pra left
    //jogar o maior em right
    cmp_swap(v[r], v[r - 1]);


    int pivo = separa(v, l + 1, r - 1);
    quicksort(v, l, pivo - 1);
    quicksort(v, pivo + 1, r);

}

int main(void){
    int n;

    while(scanf("%d", &n) != EOF){

        Bota v[10001];
        for(int i = 0; i < n; i++){
            scanf("%d %c", &v[i].m, &v[i].l);
        }

        quicksort(v, 0, n - 1);

        int i = 0;
        int j = 0;
        int k = 1;
        int conta_pares = 0;
        
        while(1){
            int conta_E = 0;
            int conta_D = 0;
            int diferenca;

            do{ 
                if(v[j].l == 'D') conta_D++;
                else conta_E++;

            }while(v[k++].m == v[j++].m && k < n);

            if(k == n){
                if(v[j].l == 'D') conta_D++;
                else conta_E++;
            
                diferenca = abs(conta_D - conta_E);
                if(conta_D > conta_E) conta_D -= diferenca;
                else conta_E -= diferenca;
                conta_pares += (conta_D + conta_E)/2;
                break;
            }

            diferenca = abs(conta_D - conta_E);    
            if(conta_D > conta_E) conta_D -= diferenca;
            else conta_E -= diferenca;
            conta_pares += (conta_D + conta_E)/2;
        }

        printf("%d\n", conta_pares);
        
    }

    return 0;
}