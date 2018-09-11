#include<stdio.h>

void helper(){
    int a=1+2+3;
}int f1(int x){helper();
    int p = 0, y = 84;
    p = x / y;

    return p;
}

int function(int x){
    int p = 0, y = 84;
    p = x / y;

    return p;
}


int main(){
    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(52);
    printf("%d\n", x);
    y = f1(52);
    printf("%d\n", y);

    x = function(34);
    printf("%d\n", x);
    y = f1(34);
    printf("%d\n", y);

    x = function(525);
    printf("%d\n", x);
    y = f1(525);
    printf("%d\n", y);

    return 0;
}
 