#include <stdio.h>
#include <string.h>

typedef struct{
    int num;
    int votos;

}Candidato;

#define less(A, B) (A < B) 
#define swap(A,B) Candidato t = A; A = B; B = t;
#define cmp_swap(A, B) if(less(A, B)){swap(A, B);}

void insertion_sort(Candidato* v, int l, int r){
    for(int i = r; i > l; i--){
        if(v[i].votos < v[i - 1].votos){
            swap(v[i], v[i - 1]);
        }
        else if(v[i].votos == v[i - 1].votos){
            if(v[i].num < v[i - 1].num){
                swap(v[i], v[i - 1]);
            }
        }

    }


    for(int i = l + 2; i <= r; i++){
        Candidato aux = v[i];
        int j = i - 1;

        while(aux.votos <= v[j].votos){
            if(aux.votos == v[j].votos && aux.num > v[j].num){
                break;
            }
            
            v[j + 1] = v[j];
            j--;
        }
        v[j] = aux;
    }


}

int busca_bin(Candidato* v, int l, int r, int input){
    if(r <= l){
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
    if(qtde_candidatos > 0){
        int res = busca_bin(candidatos, 0, *qtde_candidatos - 1, input);
        if(res != -1){
            candidatos[res].votos++;
        }
        else{
            Candidato novo;
            novo.num = input;
            novo.votos = 1;
            candidatos[*qtde_candidatos++] = novo;
            insertion_sort(candidatos, 0, *qtde_candidatos - 1);
        }
    }
    else{
        Candidato novo;
        novo.num = input;
        novo.votos = 1;
        candidatos[*qtde_candidatos++] = novo;
        insertion_sort(candidatos, 0, *qtde_candidatos - 1);
    }

}


int main(void){
    int input, invalidos = 0, n_sen, n_depF, n_depE;
    int qtde_pres = 0, qtde_sen = 0, qtde_depF = 0, qtde_depE = 0;

    Candidato* pres = malloc(sizeof(Candidato)*90);
    Candidato* sen = malloc(sizeof(Candidato)*900);
    Candidato* depF = malloc(sizeof(Candidato)*9000);
    Candidato* depE = malloc(sizeof(Candidato)*90000);

    scanf("%d %d %d", &n_sen, &n_depF, &n_depE);

    while(scanf("%d", &input) != EOF){
        if(input < 0){
            invalidos++;
        }
        else if(input < 100){
            conta_votos(input, pres, &qtde_pres);
        }
        else if(input >= 100 && input <= 999){
            conta_votos(input, sen, &qtde_sen);
        }
        else if(input >= 1000 && input <= 9999){
            conta_votos(input, depF, &qtde_depF);
        }
        else if(input >= 10000 && input <= 99999){
            conta_votos(input, depE, &qtde_depE);
        }

    }



    return 0;
}