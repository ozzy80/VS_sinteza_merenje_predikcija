#include <stdio.h>

int function(int x){
    int result=0, n = x;
    
    int i=0;
    LOOP:
        if(!(i<n)){
            goto LOOPEND;
        }
        result += x;
        x--;
        i++;
    if(i<n){
        goto LOOP;
    }
    LOOPEND:

    return result;
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