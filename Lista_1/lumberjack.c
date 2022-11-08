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
    int sair = 0;

    while(sair == 0){
        scanf("%d", &l);
        scanf("%d", &g);

        for(int i = 0; i < g; i++){
            scanf(" %c", &side[i]);
            scanf("%d", &height[i]);
        }
        scanf(" %c", &begin_side);

        scanf(" %s", &c);

        char screen[l + 1][11];

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
        for(int i = 0; i < 11; i++){
            screen[l][i] = ' ';
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
                    if(screen[0][8] == '-' || screen[1][8] == '-'){
                        printf("**beep**\n");
                        break;
                    }
                    else{
                        screen[0][9] = 'L';
                        screen[1][9] = 'L';
                        screen[0][3] = ' ';
                        screen[1][3] = ' ';
                        begin_side = 'D';
                    }

                }
                else if(c[i - 1] == 'T' && begin_side == 'D'){
                    if(screen[0][2] == '-' || screen[1][2] == '-'){
                        printf("**beep**\n");
                        break;
                    }
                    else{
                        screen[0][9] = ' ';
                        screen[1][9] = ' ';
                        screen[0][3] = 'L';
                        screen[1][3] = 'L';
                        begin_side = 'E';
                    }
                }
                else if(c[i - 1] == 'B' && begin_side == 'E' && screen[0][5] == '|'){
                    screen[0][5] = '>';
                }
                else if(c[i - 1] == 'B' && begin_side == 'D' && screen[0][7] == '|'){
                    screen[0][7] = '<';
                }
                else if(c[i - 1] == 'B' && begin_side == 'E' && screen[0][5] == '>'){
                    if(screen[2][2] == '-'){
                        printf("**morreu**\n");
                        sair++;
                        break;
                    }
                    
                    for(int line = 0; line < l; line++){
                        for(int column = 0; column < 11; column++){
                            screen[line][column] = screen[line + 1][column];
                        }
                    }
                    screen[1][3] = 'L';                

                }
                else if(c[i - 1] == 'B' && begin_side == 'D' && screen[0][7] == '<'){
                    if(screen[2][8] == '-'){
                        printf("**morreu**\n");
                        sair++;
                        break;
                    }
                    
                    for(int line = 0; line < l; line++){
                        for(int column = 0; column < 11; column++){
                            screen[line][column] = screen[line + 1][column];
                        }
                    }
                    screen[1][9] = 'L';                

                }

            }
            
            printf("~~~~~~~~~~~\n");
            for(int line = 4; line >= 0; line--){
                for(int column = 0; column < 11; column++){
                    printf("%c", screen[line][column]);
                }
                printf("\n");
            }
            printf("~~~~~~~~~~~\n");
        }
    }


    return 0;
}