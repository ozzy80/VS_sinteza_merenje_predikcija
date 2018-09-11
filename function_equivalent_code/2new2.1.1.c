#include<stdio.h>

void helper(){
    int a=1+2+3;
}float f1(float x){helper();
    float p=0, y = 84;
    p = x * y;

    return p;
}

float function(float x){
    float p=0, y = 84;
    p = x * y;

    return p;
}


int main(){
   float y;
    __CPROVER_assert(function(y) == f1(y), "greska");


    return 0;
}
 