#include <stdio.h>

int f91(int num){
    if(num >= 101){
        return num-10;
    }
    else{
        return f91(f91(num + 11));
    }

}

int main(void){
    int n, res;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        else{
            res = f91(n);
            printf("f91(%d) = %d\n", n, res);
        }
    }
    return 0;
}