#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int estado;
    int ja_perdeu;

}Particip;

typedef struct{
    Particip* v;
    int inicio;
    int fim;
    int tam;

}Fila;

int inicia_fila(Fila* f, int tam){
    f->v = malloc(sizeof(Particip)*tam);
    if(f->v == NULL) return 0;

    f->inicio = -1;
    f->fim = 0;
    f->tam = tam;

    return 1;
}

int main(void){
    int p, r, n_teste = 1;

    scanf("%d %d", &p, &r);
    while(p != 0 && r != 0){
        Fila f;
        if(inicia_fila(&f, p) != 0){
            for(int i = 0; i < p; i++){
                scanf("%d", &f.v[i].id);
                f.v[i].ja_perdeu = 0;
            }
            Particip vencedor;
            for(int i = 0; i < r; i++){
                int n, ordem, k = 0;
                scanf("%d %d", &n, &ordem);
                for(int j = 0; j < n; j++){
                    while(f.v[k].ja_perdeu != 0) k++;
                    scanf("%d", &f.v[k].estado);
                    if(f.v[k].estado != ordem) f.v[k].ja_perdeu = 1;
                    else if(i == r - 1) vencedor = f.v[k];
                    k++;

                }
            }
            printf("Teste %d\n", n_teste);
            n_teste++;
            printf("%d\n", vencedor.id);
        }
        scanf("%d %d", &p, &r);
    }


    return 0;
}