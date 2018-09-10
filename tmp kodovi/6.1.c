#include <stdio.h>

int function(int x, int y){
    int n=0, g=1;

    if(!(!x && !y)){
        x++;
        g--;
    } else if(x && !y){
        x--;
        return x;
    } else{
        g++;
        return y;
    }
   
    x += 1;
    
    return x + g;
}

int main(){

    int x = function(10, 0);
    printf("%d\n", x);
    int y = f1(10, 0);
    printf("%d\n", y);

    x = function(0, 0);
    printf("%d\n", x);
    y = f1(0, 0);
    printf("%d\n", y);

    x = function(0, 34);
    printf("%d\n", x);
    y = f1(0,34);
    printf("%d\n", y);

    return 0;
}