#include<stdio.h>

int function(int x, int n){
    int s = 1;

    int i = 0;
    for(i=0; i<abs(n); i++){
        s *= x;
    }
            
    return s;
}

int main()
{
    int x = function(10, 3);
    printf("%d\n", x);

    return 0;
}