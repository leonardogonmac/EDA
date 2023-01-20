#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int votos;

}Candidato;

#define swap(A,B) Candidato t = A; A = B; B = t;

int compara(Candidato a, Candidato b){
    if(a.votos < b.votos) return 0;
    else if(a.votos > b.votos) return 1;

    if(a.num <= b.num) return 0;
    else return 1;
}
#define cmp_swap(A, B) if(compara(A, B) == 0){swap(A, B)};


int separa(Candidato* v, int l, int r){
    if(l >= r) return r;
    Candidato p = v[r];
    int i = l - 1, j = r;

    for(;;){
        while(compara(p, v[++i]));  //while(p > v[++i])
        while(compara(v[--j], p)) if(j == l) break; //while(p < v[--j])

        if(i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[r], v[i]);
    return i;
}

void quick_sort(Candidato* v, int l, int r){
    if(l >= r) return;

    swap(v[r - 1], v[(l + r)/2]);
    cmp_swap(v[r], v[l]);
    cmp_swap(v[r - 1], v[l]);
    cmp_swap(v[r], v[r - 1]);

    int pivo = separa(v, l + 1, r - 1);
    quick_sort(v, l, pivo - 1);
    quick_sort(v, pivo + 1, r);

}

int main(void){
    int input, invalidos = 0, validos = 0, n_sen, n_depF, n_depE, qtde = 100001;


    Candidato* candidatos = malloc(sizeof(Candidato)*qtde);
    for(int i = 0; i < qtde; i++){
        candidatos[i].num = i;
        candidatos[i].votos = 0;
    }

    scanf("%d %d %d", &n_sen, &n_depF, &n_depE);

    while(scanf("%d", &input) != EOF){
       if(input < 0){
        invalidos++;
        continue;
       }
       candidatos[input].votos++;
       validos++;
    }
    quick_sort(candidatos, 10, 99);
    quick_sort(candidatos, 100, 999);
    quick_sort(candidatos, 1000, 9999);
    quick_sort(candidatos, 10000, 99999);

    int votos_pres = 0;

    for(int i = 10; i < 100; i++){
        votos_pres += candidatos[i].votos;
    }

    printf("%d %d\n", validos, invalidos);
    if(candidatos[99].votos <= votos_pres/2){
        printf("Segundo turno\n");
    }
    else{
        printf("%d\n", candidatos[99].num);
    }

    for(int i = 0; i < n_sen; i++){
        printf("%d ", candidatos[999 - i].num);

    }
    printf("\n");

    for(int i = 0; i < n_depF; i++){
        printf("%d ", candidatos[9999 - i].num);
    }
    printf("\n");

    for(int i = 0; i < n_depE; i++){
        printf("%d ", candidatos[99999 - i].num);
    }
    printf("\n");

    return 0;
}