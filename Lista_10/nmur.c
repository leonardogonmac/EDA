#include <stdio.h>
#include <stdlib.h>

int* merge_2_vet(int* v1, int* v2, int l1, int r1, int l2, int r2){
    int* vetor = malloc(sizeof(int)*((r1 - l1 + 1) + (r2 - l2 + 1)));
    
    int i1 = l1, i2 = l2, i_vetor = 0;

    while(i1 <= r1 && i2 <= r2){
        if(v1[i1] <= v2[i2]){
            vetor[i_vetor++] = v1[i1++];
        }
        else{
            vetor[i_vetor++] = v2[i2++];
        }
    }

    while(i1 <= r1){
        vetor[i_vetor++] = v1[i1++];
    }

    while(i2 <= r2){
        vetor[i_vetor++] = v2[i2++];
    }

    return vetor;

}

void merge(int* v, int l, int meio, int r){
    int v_aux[r - l + 1];
    int i1 = l, i2 = meio + 1, i_aux = 0;

    while(i1 <= meio && i2 <= r){
        if(v[i1] <= v[i2]){
            v_aux[i_aux++] = v[i1++];
        }
        else{
            v_aux[i_aux++] = v[i2++];
        }
    }

    while(i1 <= meio){
        v_aux[i_aux++] = v[i1++];
    }

    while(i2 <= r){
        v_aux[i_aux++] = v[i2++];
    }

    int i3 = 0;
    for(int i = l; i <= r; i++){
        v[i] = v_aux[i3];
        i3++;
    }

}

void mergesort(int* v, int l, int r){
    if(l == r){
        return;
    }

    int meio = (l + r)/2;
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);

    merge(v, l, meio, r);

}

int main(void){
    int n;
    scanf("%d", &n);
    int v[n + 1];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    //ordena
    mergesort(v, 0, n - 1);

    //exclui repetidos
    int novo_n = 0;
    for(int i = 1; i < n; i++){
        if(v[novo_n] != v[i]){
            v[++novo_n] = v[i];
        }
    }
    novo_n++;

    //adiciona 1 bilhao se o num de elementos for impar
    if(novo_n % 2 != 0){
        v[novo_n++] = 1000000000;
    }

    int nmu[novo_n/2];

    //gera os nmu
    int j = 0;
    for(int i = 0; i < (novo_n/2); i++){
        nmu[i] = v[j] + v[j + 1];
        j += 2;
    }

    //une v e nmu em nmur
    int tam_nmur = novo_n + (novo_n/2);
    int* nmur = merge_2_vet(v, nmu, 0, novo_n - 1, 0, (novo_n/2) - 1);

    //exclui repetidos do nmur
    int novo_tam_nmur = 0;
    for(int i = 1; i < tam_nmur; i++){
        if(nmur[novo_tam_nmur] != nmur[i]){
            nmur[++novo_tam_nmur] = nmur[i];
        }
    }
    novo_tam_nmur++;
    
    for(int i = 0; i < novo_tam_nmur; i += 4){
        printf("%d\n", nmur[i]);
    }
    printf("Elementos: %d\n", novo_tam_nmur);


    return 0;
}