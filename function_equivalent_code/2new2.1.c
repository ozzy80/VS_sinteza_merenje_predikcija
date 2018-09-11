#include<stdio.h>

void helper(){
    int a=1+2+3;
}float f1(float x, int z, float a){helper();
    float p = 0, y = 84;
    int as = 43;

    p = x * z;

    return p;
}

float function(float x, int z, float a){
    float p = 0, y = 84;
    int as = 43;

    p = x * z;

    return p;
}


int main(){
    float x, z;
    int y;
  __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
 