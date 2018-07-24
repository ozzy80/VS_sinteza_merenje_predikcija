#include <stdio.h>

int condition(int x, int y){
    
    if(x || y)
        return y;
    else
        return x;
    
    int i=0;
    int j=0;
    int a = 4;
    i++;
    i += 1;
    i--;

    j++;
    j--;

    switch(a){
        case 1:
            i += 5;
            break;
        case 2:
            i += 41;
            break;
        case 3:
            i += 74;
            break;
        default:
            i -= 15; 
    }
}

int main(){

    int x = condition(10, 15);
    printf("%d\n", x);

    return 0;
}