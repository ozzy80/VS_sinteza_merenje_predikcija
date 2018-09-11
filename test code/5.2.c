#include <stdio.h>

int function(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}

int main(){

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x,y ), "greska");

    return 0;
}