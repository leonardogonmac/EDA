#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    int votos;

}Candidato;

#define swap(A,B) Candidato t = A; A = B; B = t;
#define cmp_swap(A, B) if(A.votos < B.votos){swap(A, B);} \
                       else if(A.votos == B.votos){if(A.num < B.num){swap(A, B)};}

int separa(Candidato* v, int l, int r){
    if(l >= r) return r;
    Candidato p = v[r];
    int i = l - 1, j = r;

    for(;;){
        while(p.votos >= v[++i].votos) {
            if(p.votos == v[i].votos && p.num < v[i].num) break;
        }
        while(p.votos <= v[--j].votos) {
            if(j == l || (p.votos == v[j].votos && p.num > v[i].num)) break;
        }
        if(i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[r], v[i]);
    return i;
}

void quick_sort(Candidato* v, int l, int r){
    if(l >= r) return;
    
    swap(v[r - 1], v[(l + r)/2]); //v[r - 1] = meio
    //jogar o menor dos 3 em left
    cmp_swap(v[r], v[l]);  // se meio < left, meio vai pra left
    cmp_swap(v[r - 1], v[l]); //se right < (left ou meio), right vai pra left
    //jogar o maior em right
    cmp_swap(v[r], v[r - 1]);

    int pivo = separa(v, l + 1, r - 1);
    quick_sort(v, l, pivo - 1);
    quick_sort(v, pivo + 1, r);

}

void insertion_sort(Candidato* v, int l, int r){
    if(l == r) return;

    for(int i = r; i > l; i--){
        if(v[i].num < v[i - 1].num){
            swap(v[i], v[i - 1]);
        }
    }

    for(int i = l + 2; i <= r; i++){
        Candidato aux = v[i];
        int j = i - 1;

        while(aux.num < v[j].num){
            v[j + 1] = v[j];
            j--;
        }
        v[j] = aux;
    }

}

int busca_bin(Candidato* v, int l, int r, int input){
    if(r < l){
        return -1;
    }
    int meio = (l + r)/2;

    if(input < v[meio].num){
        return busca_bin(v, l, meio - 1, input);
    }
    else if(input > v[meio].num){
        return busca_bin(v, meio + 1, r, input);
    }
    else{
        return meio;
    }
}

void conta_votos(int input, Candidato* candidatos, int* qtde_candidatos){
    int qtde = *qtde_candidatos;
    
    if(*qtde_candidatos > 0){
        int res = busca_bin(candidatos, 0, *qtde_candidatos - 1, input);
        if(res != -1){
            candidatos[res].votos++;
        }
        else{   
            candidatos[qtde].num = input;
            candidatos[qtde].votos = 1;
            qtde++;
            insertion_sort(candidatos, 0, *qtde_candidatos - 1); //ordena com base em num
        }
    }
    else{
        candidatos[qtde].num = input;
        candidatos[qtde].votos = 1;
        qtde++;
        insertion_sort(candidatos, 0, *qtde_candidatos - 1); //ordena com base em num
    }
    *qtde_candidatos = qtde;

}

int main(void){
    int input, invalidos = 0, validos = 0, n_sen, n_depF, n_depE;
    int qtde_pres = 0, qtde_sen = 0, qtde_depF = 0, qtde_depE = 0;

    Candidato* pres = malloc(sizeof(Candidato)*99); //90 max
    Candidato* sen = malloc(sizeof(Candidato)*999); //90*10
    Candidato* depF = malloc(sizeof(Candidato)*9999); //90*10*10
    Candidato* depE = malloc(sizeof(Candidato)*99999); //90*10*10*10

    scanf("%d %d %d", &n_sen, &n_depF, &n_depE);

    while(scanf("%d", &input) != EOF){
        if(input < 0){
            invalidos++;
        }
        else if(input < 100){
            conta_votos(input, pres, &qtde_pres);
            validos++;
        }
        else if(input >= 100 && input <= 999){
            conta_votos(input, sen, &qtde_sen);
            validos++;
        }
        else if(input >= 1000 && input <= 9999){
            conta_votos(input, depF, &qtde_depF);
            validos++;
        }
        else if(input >= 10000 && input <= 99999){
            conta_votos(input, depE, &qtde_depE);
            validos++;
        }

    }
    //ordena com base em votos
    quick_sort(pres, 0, qtde_pres - 1);
    quick_sort(sen, 0, qtde_sen - 1);
    quick_sort(depF, 0, qtde_depF - 1);
    quick_sort(depE, 0, qtde_depE - 1);
    //Resultado:
    printf("%d %d\n", validos, invalidos);
    
    if(qtde_pres > 1 && pres[qtde_pres - 1].votos == pres[qtde_pres - 2].votos){
        printf("Segundo turno\n");
    }
    else{
        printf("%d\n", pres[qtde_pres - 1].num);
    }

    for(int i = 0; i < n_sen; i++){
        printf("%d ", sen[qtde_sen - (1 + i)].num);
    }
    printf("\n");

    for(int i = 0; i < n_depF; i++){
        printf("%d ", depF[qtde_depF - (1 + i)].num);
    }
    printf("\n");

    for(int i = 0; i < n_depE; i++){
        printf("%d ", depE[qtde_depE - (1 + i)].num);
    }    
    printf("\n");


    return 0;
}