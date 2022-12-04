#include <stdio.h>

void soma_limite(int* v, int i, int lim, int soma){  // {33 51 23 94 66 28 11 73 19 8 31}  lim = 90
    if(i == 1){
        return;
    }
    
    soma += *v; // (1)soma = [33] | (2)soma [51] | (3) soma > 90 [23] | (4) soma  [94] | (5) soma [66] | (6) soma [28] 
    // (7) soma [73] |(8) soma [19] | (9) soma [8] | (10) soma [31] | (11) soma | (12) return
    if(soma > lim){
        soma = 0;
        soma_limite(v + 1, i - 1, lim, soma);
        printf("%d\n", *v); // 
    }
    else{
        soma_limite(v + 1, i - 1, lim, soma);
    }    

}

int main(void){
    int vet[1000], num, lim, i = 0, soma = 0;
   
    while(scanf("%d", &num)){
        if(num == 0){
            break;
        }
        else{
            vet[i] = num;
            i++;
        }
    }

    scanf("%d", &lim); // lim = 90
    soma_limite(vet, i + 1, lim, soma);

    return 0;
}