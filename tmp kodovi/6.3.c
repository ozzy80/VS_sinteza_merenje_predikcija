#include <stdio.h>

int function(int x, int y){
    
    if(x || y){
        return y;
    }
    else{
        return x;
    }
    
    int i=0;
    int j=0;
    int aa = 4;
    i++;
    i += 1;
    i--;

    j++;
    j--;

     switch(aa){
        case 1: i += 5; break;
        case 2: i += 41; break;
        case 3: i += 74; break;
        default: i -= 15; 
    }
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