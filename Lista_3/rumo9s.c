#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mult9(char n[1001], int grau){
    int s = 0;
    char s_str[1001];
    int ret;
    
    for(int i = strlen(n) - 1; i >= 0; i--){
        s += n[i] - 48;
    }
    sprintf(s_str, "%d", s);


    if(s == 9){
        return grau;
    }
    else if(s > 9){
        ret = mult9(s_str, grau + 1);
        return ret;
    }
    else{
        return 0;
    }

}

int main(void){
    char n[1001];
    int grau = 1;
    int ret;

    while(scanf(" %s", n) != EOF){
        if(n[0] == '0'){
            break;
        }
        else{
            ret = mult9(n, grau);
            if(ret == 0){
                printf("%s is not a multiple of 9.\n", n);
            }
            else{
                printf("%s is a multiple of 9 and has 9-degree %d.\n", n, ret);
            }

        }
    }

    return 0;
}