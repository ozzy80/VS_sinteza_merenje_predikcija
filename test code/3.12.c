#include<stdio.h>

int function(int n){
    int s = 0;

    int i;
    for(i=1; i<=n; i++){
        s += i*i;
        s /= 2;
    }
        
    return s;
}

int main()
{
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