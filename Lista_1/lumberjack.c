#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int l;
    int g;
    int height[500];
    char side[500];
    char begin_side;
    char c[2000];

    printf("Tamanho arvore:\n");
    scanf("%d", &l);
    printf("TAM %d\n", l);

    printf("qtde galhos:\n");
    scanf("%d", &g);
    printf("QTDE G %d\n", g);

    for(int i = 0; i < g; i++){
        printf("Lado e altura\n");
        scanf(" %c", &side[i]);
        scanf("%d", &height[i]);
        printf("SIDE %c  HEIGHT %d\n", side[i], height[i]);
    }
    printf("Lado de inicio\n");
    scanf(" %c", &begin_side);
    printf("BEGIN %c\n", begin_side);

    printf("comandos\n");
    scanf(" %s", &c);
    printf("RES %s   STRLEN %d\n", c, strlen(c));

    char screen[l][11];

    for(int line = 0; line < l; line++){
        for(int column = 0; column < 11; column++){
            if(column > 4 && column < 8){
                screen[line][column] = '|';
            }
            else{
                screen[line][column] = ' ';

            }
        }
    }

    if(begin_side == 'E'){
        screen[0][3] = 'L';
        screen[1][3] = 'L';
    }
    else{
        screen[0][9] = 'L';
        screen[1][9] = 'L';
    }

    for(int i = 0; i < g; i++){
        if(side[i] == 'E'){
            screen[height[i] - 1][2] = '-';
            screen[height[i] - 1][3] = '-';
            screen[height[i] - 1][4] = '-';


        }
        else{
            screen[height[i] - 1][8] = '-';
            screen[height[i] - 1][9] = '-';
            screen[height[i] - 1][10] = '-';
        }
    }

    for(int i = 0; i <= strlen(c); i++){
        if(i != 0){
            if(c[i - 1] == 'T' && begin_side == 'E'){
                screen[0][9] = 'L';
                screen[1][9] = 'L';
                screen[0][3] = ' ';
                screen[1][3] = ' ';
                begin_side = 'D';

            }
            else if(c[i - 1] == 'T' && begin_side == 'D'){
                screen[0][9] = ' ';
                screen[1][9] = ' ';
                screen[0][3] = 'L';
                screen[1][3] = 'L';
                begin_side = 'E';
            }

        }
        
        printf("~~~~~~~~~~~\n");
        for(int line = l - 1; line >= 0; line--){
            for(int column = 0; column < 11; column++){
                printf("%c", screen[line][column]);
            }
            printf("\n");
        }
        printf("~~~~~~~~~~~\n");
    }


    return 0;
}