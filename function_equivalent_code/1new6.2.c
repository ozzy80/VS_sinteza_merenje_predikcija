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

int f1(int x, int y, int z){
    int n=0, g=1;

    if(!(!x && !y)){
        if(x == n){
            x++;
            g = 
            g - 1;
;
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

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
