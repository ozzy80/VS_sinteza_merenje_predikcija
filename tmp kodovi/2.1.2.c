#include<stdio.h>

int tmp(int x){
    int p = 0, y = 84;
    p = x / y;

    return p;
}

int main(){
    int x = 55;
    printf("%d\n", tmp(x));

    return 0;
}
 