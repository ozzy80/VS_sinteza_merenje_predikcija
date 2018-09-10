#include <stdio.h>

int function(int x, int y, int z){
    int n=0, g=1;

    if(!(!x && !y)){
        if(x == n){
            x++;
            g--;
        }
        else if(!z){
            x--;
            g++;
        }
        return y;
    } 
    else if(x && !z){
        return x;
    }
    x += 1;
    
    return x + y + g +z;
}

int main(){

    int x = function(10, 0, 3);
    printf("%d\n", x);
    int y = f1(10, 0, 3);
    printf("%d\n", y);

    x = function(0, 0, 3);
    printf("%d\n", x);
    y = f1(0, 0, 3);
    printf("%d\n", y);

    x = function(0, 34, 3);
    printf("%d\n", x);
    y = f1(0,34, 3);
    printf("%d\n", y);

    return 0;
}