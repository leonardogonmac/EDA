#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* cartas;
    int topo;

}Pilha;

int inicia_pilha(Pilha* p, int tam){
    p->cartas = malloc(sizeof(int)*tam);
    if(p->cartas == NULL) return 0;
    p->topo = 0;
    return 1;
}
void desempilha(Pilha* p){
    if(p->topo == 0) return;

    p->topo--;
}
void insere_elem(Pilha* p, int e){
    p->cartas[p->topo] = e;
    p->topo++;
}
void joga_no_fundo(Pilha* p){
    int aux = p->cartas[p->topo - 1];
    for(int i = p->topo - 1; i > 0; i--){
        p->cartas[i] = p->cartas[i - 1];
    }
    p->cartas[0] = aux;
}

int main(void){
    int n;
    scanf("%d", &n);
    Pilha p;
    inicia_pilha(&p, n);
    //empilha cartas
    for(int i = n; i > 0; i--){
        insere_elem(&p, i);        
    }
    printf("Cartas descartadas: ");
    while(1){
        if(p.topo == 2){
            printf("%d\n", p.cartas[p.topo - 1]);
            desempilha(&p);
            break;        
        }
        
        printf("%d, ", p.cartas[p.topo - 1]);
        desempilha(&p);
        joga_no_fundo(&p);

    }
    printf("Carta restante: %d\n", p.cartas[p.topo - 1]);

    return 0;
}