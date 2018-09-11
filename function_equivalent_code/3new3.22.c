#include<stdio.h>

void helper(){
    int a=1+2+3;
}int f1(int x, int n){helper();
    int s = 1;

    int i = 0;
    for(i=0; i<abs(n); i++){
        s *= x;
    }
            
    return s;
}

int function(int x, int n){
    int s = 1;

    int i = 0;
    for(i=0; i<abs(n); i++){
        s *= x;
    }
            
    return s;
}


int main(){

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x,y ), "greska");
    
    return 0;
}