#include <stdio.h>

void helper(){
    int a=1+2+3;
}int f1(int x,int y,int c){helper();
    int k = x+y<3;
    if(k>=c)
        return 2;
    return 3;
}

int function(int x,int y,int c){
    int k = x+y<3;
    if(k>=c)
        return 2;
    return 3;
}


int main(){

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}