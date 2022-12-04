#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int chutes_res1 = n, chutes_res2 = n, lance_atual = 1, lance_fim = 0;

    char time1[n + 1];
    char time2[n + 1];
    int gols1 = 0, gols2 = 0;

    scanf(" %s", time1);
    scanf(" %s", time2);


    for(int i = 0; i < n; i++){
        //lances do time1
        if(time1[i] == 'o'){
            gols1++;
        }
        chutes_res1--;

        if(gols2 > gols1 + chutes_res1 || gols1 > gols2 + chutes_res2){
            lance_fim = lance_atual;
            break;
        }
        lance_atual++;

        //lances do time2
        if(time2[i] == 'o'){
            gols2++;
        }
        chutes_res2--;

        if(gols2 > gols1 + chutes_res1 || gols1 > gols2 + chutes_res2){
            lance_fim = lance_atual;
            break;
        }
        lance_atual++;
    }
    
    if(lance_fim == 0){
        printf("Empate\n");
    }
    else{
        printf("%d\n", lance_fim);
    }

    return 0;
}