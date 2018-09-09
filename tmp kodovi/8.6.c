#include <stdio.h>

int function(int x){
    int f=1;

    int i = 1;
    while (i < x+1)
    {
        if(i > 12)
            break;
        f = f * i; 
        i++;  
    }
    return f;
}

int main(){

    int x = function(10);
    printf("%d\n", x);

    return 0;
}