#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char string[10];
    int contador_sim = 0;
    int formulario = 0;
    int sair = 0;

    while(sair == 0){        
        int c_sim = 0;
        for(int i = 0; i < 10; i++){
            if(scanf("%s", &string) != EOF){
                if(strcmp(string, "sim") == 0){
                    c_sim++;
                   
                }
                if(i == 9 && c_sim >= 2){
                    contador_sim++;
                }
            }
            else{
                sair++;
                if(c_sim >= 2){
                    contador_sim++;
                }
                break;
            }
        }
    }

    printf("%d\n", contador_sim);
    
    return 0;
}