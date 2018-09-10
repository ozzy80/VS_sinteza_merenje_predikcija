#include<stdio.h>

int function(int n){
    int ukupno = 0, j;

    int i;
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            ukupno += i*j;
        }            
    }
    return ukupno;
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