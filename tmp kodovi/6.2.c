#include <stdio.h>

int function(int x, int y, int z){
    int n=0, a=1;

    if(!(!x && !y)){
        if(x == n){
            x++;
            a--;
        }
        else if(!z){
            x--;
            a++;
        }
        return y;
    } 
    else if(x && !z){
        return x;
    }
    x += 1;
    
    return !(!x && !y) ? y : z;
}

int main(){

    int x = function(0, 0, 1);
    printf("%d\n", x);

    return 0;
}