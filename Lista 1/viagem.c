#include <stdio.h>
#include <stdlib.h>

int main(void){
    int r;
    int dia = 1;
    int codigo;
    int nota;
    int maior_nota = 0;
    int codigo_maior_nota = 0;

    while(scanf("%d", &r) != EOF){
        maior_nota = 0;
        codigo_maior_nota = 100000000;

        for(int i = 0; i < 2*r; i++){
            if(i % 2 == 0){
                scanf("%d", &codigo);
            }
            else{
                scanf("%d", &nota);
                if(nota > maior_nota){
                    maior_nota = nota;
                    codigo_maior_nota = codigo;
                }
                else if(nota == maior_nota && codigo < codigo_maior_nota){
                    codigo_maior_nota = codigo;
                }
            }
        }

        printf("Dia %d\n", dia);
        printf("%d\n", codigo_maior_nota);
        printf("\n");
        
        dia++;


    }

    return 0;
}