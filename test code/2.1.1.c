#include<stdio.h>

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
 