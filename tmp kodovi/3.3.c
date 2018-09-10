#include <stdio.h>

int function(int x){
    int f=1;

    int i = 1;
    while (i < x){
        f = f * i; 
        i++;  
    }
    return f;
}

int main(){

    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(8);
    printf("%d\n", x);
    y = f1(8);
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