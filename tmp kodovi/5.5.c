#include <stdio.h>

int function(int x,int y,int c){
    int l=x+y+c;
    if(l==17)
        return 2;
    return 3;
}

int main(){
    int x = function(10, 0, 51);
    printf("%d\n", x);
    int y = f1(10, 0, 51);
    printf("%d\n", y);

    x = function(0, 0, 51);
    printf("%d\n", x);
    y = f1(0, 0, 51);
    printf("%d\n", y);

    x = function(0, 34, 51);
    printf("%d\n", x);
    y = f1(0,34, 51);
    printf("%d\n", y);
    return 0;
}