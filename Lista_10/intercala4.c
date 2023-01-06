#include <stdio.h>
#include <stdlib.h>

int* intercala2(int* v1, int* v2, int l1, int r1, int l2, int r2){
    int* v_ret = malloc(sizeof(int)*((r1 - l1 + 1) + (r2 - l2 + 1)));
    int i1 = l1, i2 = l2, i_ret = 0;
    // v {1 3 5 7 2 4 6 8}
    //v1 = {1 3 5 7 } r = 3
    //v2 = {2 4 6 8 } r = 3
    
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

int* intercala4(int* v1, int* v2, int* v3, int* v4, int l1, int r1, int l2, int r2, int l3, int r3, int l4, int r4){
    int* v1_2 = intercala2(v1, v2, l1, r1, l2, r2);
    int* v3_4 = intercala2(v3, v4, l3, r3, l3, r4);

    int r1_2 = r1 + r2 + 1;
    int r3_4 = r3 + r4 + 1;

    int* v_final = intercala2(v1_2, v3_4, 0, r1_2, 0, r3_4);


}

int main(void){
    int* vetores[4];
    int qtde[4];

    for(int i = 0; i < 4; i++){
        printf("qtde de num\n");
        scanf("%d", &qtde[i]);
        vetores[i] = malloc(sizeof(int)*qtde[i]);
        for(int j = 0; j < qtde[i]; j++){
            scanf("%d", &vetores[i][j]);
        }

    }

    int* v = intercala4(vetores[0], vetores[1], vetores[2], vetores[3], 
                        0, qtde[0] - 1, 0, qtde[1] - 1, 0, qtde[2] - 1, 0, qtde[3] - 1);

    int tam = qtde[0] + qtde[1] + qtde[2] + qtde[3];
    for(int i = 0; i < tam; i++){
        printf("%d\n", v[i]);
    }


}