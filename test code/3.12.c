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

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}