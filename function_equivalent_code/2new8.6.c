#include <stdio.h>

int function(int x){
    int f=1;

    int i = 1;
    while (i < x)
    {
        if(i > 12)
            break;
        f *= i; 
        i++;  
    }
    return f;
}

int f1(int x){
    int f=1;

    int i = 1;
    while (i < x)
    {
        if(i > 12)
            break;
        f *= i; 
        i = 
        i + 1;
;  
    }
    return f;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
