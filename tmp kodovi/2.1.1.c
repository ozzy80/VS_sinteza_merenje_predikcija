#include<stdio.h>

float function(float x){
    float p=0, y = 84;
    p = x * y;

    return p;
}

int main(){
    int x = 55;
    printf("%f\n", function(x));

    return 0;
}
 