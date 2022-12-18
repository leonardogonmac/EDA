#include <stdio.h>
#include <stdlib.h>

int* merge2(int* v1, int* v2, int l1, int r1, int l2, int r2){
    int* v_ret = malloc(sizeof(int)*((r1 - l1 + 1) + (r2 - l2 + 1)));
    int i1 = l1, i2 = l2, i_ret = 0;
    
    while(i1 <= r1 && i2 <= r2){
        if(v1[i1] <= v2[i2]){
            v_ret[i_ret++] = v1[i1++];
        }
        else{
            v_ret[i_ret++] = v2[i2++];
        }
    }

    while(i1 <= r1){
        v_ret[i_ret++] = v1[i1++];
    }

    while(i2 <= r2){
        v_ret[i_ret++] = v2[i2++];
    }

    return v_ret;

}

int main(void){
    int qtdes[8];
    int* vetores[8];
    int* vetor_intercalado;
    int qtde_intercalado;

    for(int i = 0; i < 8; i++){
        scanf("%d", &qtdes[i]);
        vetores[i] = malloc(sizeof(int)*qtdes[i]);
        
        for(int j = 0; j < qtdes[i]; j++){
            scanf("%d", &vetores[i][j]);
        }
    }

    int k;
    for(k = 0; k < 8; k++){
        if(qtdes[k] > 0){
            vetor_intercalado = vetores[k];
            break;
        }
    }

    qtde_intercalado = qtdes[k];
    for(int i = k + 1; i < 8; i++){
        if(qtdes[i] == 0){
            continue;
        }
        
        vetor_intercalado = merge2(vetor_intercalado, vetores[i], 0, qtde_intercalado - 1, 0, qtdes[i] - 1);
        qtde_intercalado += qtdes[i];
    }

    for(int i = 0; i < qtde_intercalado; i++){
        printf("%d ", vetor_intercalado[i]);
    }
    printf("\n");


    return 0;
}