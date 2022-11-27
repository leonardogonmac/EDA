#include <stdio.h>

int main(void){
    int diam, alt, lar, pro;
    scanf("%d", &diam);
    scanf("%d %d %d", &alt, &lar, &pro);

    if(alt >= diam && lar >= diam && pro >= diam){
        printf("S\n");
    }
    else{
        printf("N\n");
    }

    return 0;
}