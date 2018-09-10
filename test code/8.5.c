#include <stdio.h>

int function(int x){
    int f=1;

    int i = 1;
    while (i < x){
        if(i%2 == 0){
            i++;
            continue;  
        }
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