#include <stdio.h>
#include <stdlib.h>

struct cel{
    int numero;
    struct cel* prox;

};

typedef struct{
    struct cel* inicio;    
    int qtde;

}cabeca;

void inicia_cabeca(cabeca* h){
    h->inicio = NULL;
    h->qtde = 0;
}

void bota_no(cabeca* h, int e){
    struct cel* novo_no = malloc(sizeof(struct cel));
    novo_no->numero = e;
    novo_no->prox = h->inicio;
    h->inicio = novo_no;
}

void separa(cabeca* h, cabeca* hpar, cabeca* himpar){
    struct cel* aux = h->inicio;
    while(aux != NULL){
        if(aux->numero % 2 == 0){
            bota_no(hpar, aux->numero);
        }
        else{
            bota_no(himpar, aux->numero);
        }
        aux = aux->prox;
    }

}

void copia_vetor(cabeca* h, int* v, int tam){
    for(int i = tam - 1; i >= 0; i--){
        bota_no(h, v[i]);
    }
}

int copia_lista(cabeca* h, int* v){
    struct cel* aux = h->inicio;
    int qtde = 0;
    while(aux != NULL){
        v[qtde] = aux->numero;
        qtde++;
        aux = aux->prox;
    }

    return qtde;
}

int main(void){
    /*cabeca h, hpar, himpar;
    inicia_cabeca(&h);
    int num1 = 13, num2 = 4, num3 = 7, num4 = 10, num5 = 19;
    bota_no(&h, num1);
    bota_no(&h, num2);
    bota_no(&h, num3);
    bota_no(&h, num4);
    bota_no(&h, num5);

    inicia_cabeca(&hpar);
    inicia_cabeca(&himpar);
    separa(&h, &hpar, &himpar);

    struct cel* aux = hpar.inicio;
    while(aux != NULL){
        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");

    struct cel* aux2 = himpar.inicio;
    while(aux2 != NULL){
        printf("%d ", aux2->numero);
        aux2 = aux2->prox;
    }
    printf("\n");*/

    /*cabeca h;
    inicia_cabeca(&h);
    int tam = 10;
    int v[tam];
    for(int i = 0; i < 10; i++){
        v[i] = i;
    }

    copia_vetor(&h, v, tam);

    struct cel* aux = h.inicio;
    while(aux != NULL){
        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");*/

    cabeca h;
    inicia_cabeca(&h);
    int num1 = 13, num2 = 4, num3 = 7, num4 = 10, num5 = 19;
    bota_no(&h, num1);
    bota_no(&h, num2);
    bota_no(&h, num3);
    bota_no(&h, num4);
    bota_no(&h, num5);

    int v[10];

    int qtde = copia_lista(&h, v);

    for(int i = 0; i < qtde; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}