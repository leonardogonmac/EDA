#include <stdio.h>

void printx(char* p_string){
    if(*p_string == '\0'){
        return;
    }
    else if(*p_string == 'x'){
        printf("%c", *p_string);
        printx(p_string + 1);
    }
    else{
        printx(p_string + 1);
    }
    

}

void move(char* p_string, int contador){
    if(*p_string == '\0'){
        return;
    }
    else if(*p_string != 'x'){
        printf("%c", *p_string);
        move(p_string + 1, contador + 1);
    }
    else{
        move(p_string + 1, contador + 1);
    }

    if (contador == 0){
        if(*p_string == 'x'){
            printf("%c", *p_string);
        }
        
        printx(p_string + 1);

    }
    
}



int main(void){
    char string[101];
    int contador = 0;

    scanf("%s", string);
    move(string, contador);

    printf("\n");


    return 0;
}