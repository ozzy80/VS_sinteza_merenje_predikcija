#include <stdio.h>

int function(int x,int y,int c){
    if(x<=y && y>c)
        return 2;
    return 3;
}

int main(){
    int x = function(10, 0, 0);
    printf("%d\n", x);
    int y = f1(10, 0, 0);
    printf("%d\n", y);

    x = function(0, 0, 1);
    printf("%d\n", x);
    y = f1(0, 0, 1);
    printf("%d\n", y);

    x = function(0, 34, 1);
    printf("%d\n", x);
    y = f1(0,34, 1);
    printf("%d\n", y);
    return 0;
}