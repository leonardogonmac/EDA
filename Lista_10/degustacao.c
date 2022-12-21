#include <stdio.h>
#include <string.h>

typedef struct{
    int qtde;
    char letra;
    int inicio;

}Letras;

void merge(Letras* vetor, int l, int meio, int r){
    Letras v_aux[r - l + 1];
    int i1 = l, i2 = meio + 1, i_aux = 0;

    while(i1 <= meio && i2 <= r){
        if(vetor[i1].qtde < vetor[i2].qtde){
            v_aux[i_aux++] = vetor[i1++];
        }
        else{
            v_aux[i_aux++] = vetor[i2++];
        }
    }

    while(i1 <= meio){
        v_aux[i_aux++] = vetor[i1++];
    }

    while(i2 <= r){
        v_aux[i_aux++] = vetor[i2++];
    }

    int i3 = 0;
    for(int i = l; i <= r; i++){
        vetor[i] = v_aux[i3++];
    }


}

void mergesort(Letras* vetor, int l, int r){
    if(l == r){
        return;
    }

    int meio = (l + r)/2;
    mergesort(vetor, l, meio);
    mergesort(vetor, meio + 1, r);

    merge(vetor, l, meio, r);

}

int main(void){
    char string[100001];
    int contador, inicio, j = 0;
    scanf(" %s", string);

    int tam = strlen(string);
    Letras vetor[tam];

    for(int i = 0; i <= tam; i++){
        if(i == 0 || string[i] != string[i - 1]){
            if(i != 0){
                vetor[j].qtde = contador;
                vetor[j].letra = string[i - 1];
                vetor[j].inicio = inicio;
                j++;
            }
            contador = 1;
            inicio = i;
        }
        
        if(string[i] == string[i + 1]){
            contador++;
        }

    }

    mergesort(vetor, 0, j - 1);// ordena o vetor de structs pela qtde

    for(int i = j - 1 ; i >= 0; i--){
        printf("%d %c %d\n", vetor[i].qtde, vetor[i].letra, vetor[i].inicio);
    }

    return 0;
}