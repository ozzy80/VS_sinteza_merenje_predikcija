#include <stdio.h>

void helper(){
    int a=1+2+3;
}int f1(int x,int y,int c){helper();
    int v=x+y;
    if(v!=17)
        return 6;
    return 8;
}

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