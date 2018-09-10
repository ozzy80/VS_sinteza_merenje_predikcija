#include<stdio.h>

int function(int x, int n){
    int s = 1;

    int i = 0;
    for(i=0; i<abs(n); i++){
        s *= x;
    }
            
    return s;
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