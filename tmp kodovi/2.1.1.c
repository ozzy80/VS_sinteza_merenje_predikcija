#include<stdio.h>

float tmp(float x){
    float p=0, y = 84;
    p = x * y;

    return p;
}

int main(){
    int x = 55;
    printf("%f\n", tmp(x));

    return 0;
}
 