#include<stdio.h>

int function(int x1, int x2){
    int r = 1;

    int x = x1;
    int y = x2;
    while(y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    int x = function(10, 3);
    printf("%d\n", x);
    int y = f1(10, 3);
    printf("%d\n", y);

    x = function(52, 3);
    printf("%d\n", x);
    y = f1(52, 3);
    printf("%d\n", y);

    x = function(34, 3);
    printf("%d\n", x);
    y = f1(34, 3);
    printf("%d\n", y);

    x = function(525, 3);
    printf("%d\n", x);
    y = f1(525, 3);
    printf("%d\n", y);

    return 0;
}