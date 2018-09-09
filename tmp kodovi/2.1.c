#include<stdio.h>

float function(float x, int z, float a){
    float p, y = 84;
    int as = 43;

    p = x + x + y * z + a - 15;

    return p;
}

void read(){
    float m, n ;
    printf("\nEnter some number for finding square \n");
    scanf("%f", &m);

    n = function(m, 18, 14.21);

    printf("\nSome value of the given number %f is %f\n",m ,n);
}

int main(){
    read();
}
 