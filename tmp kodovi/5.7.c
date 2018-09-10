#include <stdio.h>

int function(int x,int y,int c){
    if(x||y)
        return c;
    return 8;
}

int main(){
    int x = function(10, 0, 3);
    printf("%d\n", x);
    int y = f1(10, 0, 3);
    printf("%d\n", y);

    x = function(0, 0, 3);
    printf("%d\n", x);
    y = f1(0, 0, 3);
    printf("%d\n", y);

    x = function(0, 34, 3);
    printf("%d\n", x);
    y = f1(0,34, 3);
    printf("%d\n", y);

    return 0;
}