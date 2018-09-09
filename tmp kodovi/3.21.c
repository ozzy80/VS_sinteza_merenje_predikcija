#include<stdio.h>

int function(int a, int b){
    int r = 1;

    int x = a;
    int y = b;
    while(y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    int x = function(10, 5);
    printf("%d\n", x);

    return 0;
}