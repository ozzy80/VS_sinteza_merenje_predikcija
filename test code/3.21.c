#include<stdio.h>

int function(int x1, int x2){
    int r = 1;

    int x = x1;
    int y = x2;
    while(y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main(){

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x,y ), "greska");

    return 0;
}