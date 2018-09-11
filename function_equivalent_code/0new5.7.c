#include <stdio.h>

int function(int x,int y,int c){
    if(x||y)
        return c;
    return 8;
}

int f1(int x,int y,int c){
    if(!(!(x)&&!(y)))
        return c;
    return 8;
}

int main(){

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
