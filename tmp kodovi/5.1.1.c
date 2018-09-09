#include <stdio.h>

int function(int x, int y){
    return (x||y);
    
}

int main(){

    int x = function(10, 15);
    printf("%d\n", x);

    return 0;
}