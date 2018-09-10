#include <stdio.h>

int function(int x,int y,int c){
    int k = x+y<3;
    if(k>=c)
        return 2;
    return 3;
}

int main(){
    int x = function(10, 0, 2);
    printf("%d\n", x);
    int y = f1(10, 0, 2);
    printf("%d\n", y);

    x = function(0, 0, 2);
    printf("%d\n", x);
    y = f1(0, 0, 2);
    printf("%d\n", y);

    x = function(0, 34, 2);
    printf("%d\n", x);
    y = f1(0,34, 2);
    printf("%d\n", y);

    return 0;
}