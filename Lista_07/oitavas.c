#include <stdio.h>

int main(void){
    char oitavas[16];
    char quartas[8];
    char semif[4];
    char final[2];
    int gols[2];
    int j = 0, k = 0;

    for(int i = 'A'; i <='P'; i++){
        oitavas[j] = i;
        j++;
    }
    j = 0;
    
    for(int i = 1; i <= 15; i++){
        scanf("%d %d", &gols[0], &gols[1]);
        if(i < 9){
            if(gols[0] > gols[1]){
                quartas[j] = oitavas[k];
                j++;
                k +=2; 
            }
            else{
                quartas[j] = oitavas[k + 1];
                j++;
                k += 2;
            }

            if(i == 8){
                j = 0;
                k = 0;
            }
        }
        else if(i < 13){
            if(gols[0] > gols[1]){
                semif[j] = quartas[k];
                j++;
                k +=2; 
            }
            else{
                semif[j] = quartas[k + 1];
                j++;
                k += 2;
            }

            if(i == 12){
                j = 0;
                k = 0;
            }
        }
        else if(i < 15){
            if(gols[0] > gols[1]){
                final[j] = semif[k];
                j++;
                k +=2; 
            }
            else{
                final[j] = semif[k + 1];
                j++;
                k += 2;
            }

            if(i == 14){
                j = 0;
                k = 0;
            }
        }
        else{
            if(gols[0] > gols[1]){
                printf("%c\n", final[j]);
            }
            else{
                printf("%c\n", final[j + 1]);
            }
        }

    }

    return 0;
}