#include <stdio.h>

void string_contrario(char* string){
    if(*string == '\0'){
        return;
    }
    else{
        string_contrario(string + 1); 
        printf("%c", *string);
    }

}

int main(void){
    char string[501];
    scanf(" %s", string);
    string_contrario(string);
    printf("\n");
    
    return 0;
}