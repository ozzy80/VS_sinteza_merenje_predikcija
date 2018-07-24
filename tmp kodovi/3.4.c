#include <stdio.h>

int function(int x){
    int result=0, n = x;
    
    int i=0;
    LOOP:
        result += x;
        x--;
        i++;
    if(i<n){
        goto LOOP;
    }

    return result;

       TOT:
        result += x;
        x--;
        i++;
    if(i<n){
        goto TOT;
    }
}

int main(){

    int x = function(10);
    printf("%d\n", x);

    return 0;
}