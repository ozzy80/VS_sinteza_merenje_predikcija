#include<stdio.h>

int function(int n){
    int s = 0;

    int i;
    for(i=1; i<=n; i++){
        s += i*i*i;
    }
        
    return s;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}