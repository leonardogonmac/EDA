#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifica_sub_inicio(char* str, char* sub, int tam_sub){
    if(tam_sub == 0){
        return 1;
    }
    else if(*sub == *str){
        return verifica_sub_inicio(str + 1, sub + 1, tam_sub - 1);
    }
    else{
        return 0;
    }

}

int verifica_sub_fim(char* str, char* sub, int tam_sub){
    if(tam_sub == 0){
        return 1;
    }
    else if(*sub == *str){
        return verifica_sub_inicio(str - 1, sub - 1, tam_sub - 1);
    }
    else{
        return 0;
    }

}


char* sub_inicio(char* str, char* sub, int tam_sub){
    if(*(str + tam_sub - 1) == '\0'){
        return NULL;
    }
    if(verifica_sub_inicio(str, sub, tam_sub) == 1){
        return str;
    }
    else{
        return sub_inicio(str + 1, sub, tam_sub);
    }

}

char* sub_fim(char* str, char* last_str, char* last_sub, int tam_sub){
    if(last_str - tam_sub + 1 == str){
        return NULL;
    }
    else if(verifica_sub_fim(last_str, last_sub, tam_sub) == 1){
        return last_str;
    }
    else{
        return sub_fim(str, last_str - 1, last_sub, tam_sub);
    }

}

int conta_char(int qtde, char* inicio_str, char* fim_str){
    if(inicio_str == fim_str){
        return qtde;
    }
    else{
        return conta_char(qtde + 1, inicio_str + 1, fim_str);
    }


}

int main(void){
    char str[101];
    char sub[101];
    char* inicio_str; 
    char* fim_str;
    char* last_str;
    char* last_sub;
    int qtde = 1;
    int tam_sub, tam_str;

    scanf(" %s", str);
    scanf(" %s", sub);

    tam_sub = strlen(sub);
    tam_str = strlen(str);
    last_str = &str[tam_str - 1];
    last_sub = &sub[tam_sub - 1];

    inicio_str = sub_inicio(str, sub, tam_sub);
    if(inicio_str == NULL || tam_sub > tam_str || tam_str == 0){
        printf("0\n");
        exit(0);
    }

    fim_str = sub_fim(str, last_str, last_sub, tam_sub);

    if(fim_str == NULL){
        qtde = tam_sub;
    }
    else{
        qtde = conta_char(qtde, inicio_str, fim_str);
    }

    printf("%d\n", qtde);

    return 0;
}