#include <stdio.h>

int function(int x){
    int result=0, n = x;

    int i=0;
    while(i<n){
        result += x;
        x--;
        i++;
    }

    return result;
    int k=0;
    while(k<n){
        result += x;
    }
}

int main(){

    int x = function(10);
    printf("%d\n", x);

    return 0;
}