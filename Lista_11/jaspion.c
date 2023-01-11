#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(A, B) Traducao t = A; A = B; B = t;

typedef struct{
    char palavra_pt[81];
    char palavra_jap[81];
}Traducao;

int ordem_alf(char* palavra1, char* palavra2){
    if(*palavra1 == '\0' && *palavra2 == '\0'){
        return 3;
    }
    else if(*palavra1 == '\0'){
        return 0;
    }
    else if(*palavra2 == '\0'){
        return 1;
    }


    if(*palavra1 < *palavra2){
        return 0;
    }
    else if(*palavra1 > *palavra2){
        return 1;
    }
    else{
        ordem_alf(palavra1 + 1, palavra2 + 1);
    }
}

int busca_bin(Traducao* v, int l, int r, char* palavra){
    if(r < l){
        return (-1);
    }
    
    int meio = (r + l)/2;

    if(ordem_alf(palavra, v[meio].palavra_jap) == 0){
        return busca_bin(v, l, meio - 1, palavra);
    }
    else if(ordem_alf(palavra, v[meio].palavra_jap) == 1){
        return busca_bin(v, meio + 1, r, palavra);
    }
    else{
        return meio;
    }

}

int separa(Traducao* v, int l, int r){
    if(l >= r) return r;
    Traducao p = v[r];
    int i = l - 1, j = r;
  
    for(;;){
        while(ordem_alf(p.palavra_jap, v[++i].palavra_jap) == 1);
        while(ordem_alf(p.palavra_jap, v[--j].palavra_jap) == 0) if(j == l) break;

        if(i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[r], v[i]);
    return i;

}

void quicksort(Traducao* v, int l, int r){
    if(l >= r) return;
 
    swap(v[r - 1], v[(l + r)/2]); //v[r - 1] = meio
    //menor em left
    if(ordem_alf(v[l].palavra_jap, v[r - 1].palavra_jap) != 0){
        swap(v[l], v[r - 1])
    }
    if(ordem_alf(v[l].palavra_jap, v[r].palavra_jap) != 0){
        swap(v[l], v[r]);
    }
    //maior em right
    if(ordem_alf(v[r - 1].palavra_jap, v[r].palavra_jap) != 0){
        swap(v[r - 1], v[r]);
    }


    int pivo = separa(v, l + 1, r - 1);
    quicksort(v, l, pivo - 1);
    quicksort(v, pivo + 1, r);



}

int main(void){
    int t, m, n;
    scanf("%d", &t);
    
    for(int _ = 0; _ < t; _++){
        scanf("%d %d", &m, &n);
        Traducao* vetor = malloc(sizeof(Traducao)*m);
        char musica[81];

        for(int i = 0; i < m; i++){
            scanf(" %s", vetor[i].palavra_jap);
            scanf(" %[^\n]%*c", vetor[i].palavra_pt);
        }

        quicksort(vetor, 0, m - 1);
        
        for(int i = 0; i < n; i++){
            scanf(" %[^\n]", musica);
            
            int k = 0;
            for(;;){
                char palavra[81];
                int j = 0;
                while(musica[k] != ' ' && musica[k] != '\0'){
                    palavra[j] = musica[k];
                    j++;
                    k++;
                }
                if(musica[k] == ' '){
                    palavra[j++] = '\0';
                    int res = busca_bin(vetor, 0, m - 1, palavra);
                    if(res == -1){
                        printf("%s ", palavra);
                    }
                    else{
                        printf("%s ", vetor[res].palavra_pt);
                    }
                    k++;
                    continue;
                }
                else if(musica[k] == '\0'){
                    palavra[j++] = '\0';
                    int res = busca_bin(vetor, 0, m - 1, palavra);
                    
                    if(res == -1) printf("%s ", palavra);
                    else printf("%s\n", vetor[res].palavra_pt);
                    
                    break;
                }
            }



        }
    }

    return 0;

}