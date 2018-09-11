#include<stdio.h>

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
 