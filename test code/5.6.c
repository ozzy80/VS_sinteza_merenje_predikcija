#include <stdio.h>

int function(int x,int y,int c){
    int v=x+y;
    if(v!=17)
        return 6;
    return 8;
}

int main(){

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}