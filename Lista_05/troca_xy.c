#include <stdio.h>

void troca_xy(char* string){
    if(*string == '\0'){
        return;
    }
    else if(*string == 'x'){
       *string = 'y';
    }

    troca_xy(string + 1);

}

int main(void){
    char string[81];
    scanf(" %s", string);
    troca_xy(string);
    printf("%s\n", string);

    return 0;
}