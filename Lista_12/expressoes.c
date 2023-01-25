#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* cadeia;
    int topo;

}Pilha;

int inicia_pilha(Pilha* p, int tam){
    p->cadeia = malloc(sizeof(char)*tam);
    if(p->cadeia == NULL) return 0;
    p->topo = 0;
    return 1;
}
void desempilha(Pilha* p){
    if(p->topo == 0) return;

    p->topo--;
}

int main(void){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        Pilha p;
        if(inicia_pilha(&p, 100001) != 0){
            char str[100001];
            scanf("%s", str);
            int len = strlen(str);
            char* str2 = str;
            while(*str2 != '\0'){
                if(p.topo > 0 && (*str2 == p.cadeia[p.topo - 1] + 1 || *str2 == p.cadeia[p.topo - 1] + 2)){
                    desempilha(&p);
                    str2 += 1;
                }
                else{
                    p.cadeia[p.topo] = *str2;
                    p.topo++;
                    str2 += 1;
                }
            }
            if(p.topo == 0){
                printf("S\n");
            }
            else{
                printf("N\n");
            }

        }
    }

    return 0;
}