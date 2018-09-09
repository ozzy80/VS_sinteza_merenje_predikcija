#include <stdio.h>

int function(int a,int b,int c){
    if(a||b && c)
        return 6;
    return 8;
}

int main(){
    printf("%d",function(1,0,1));
    return 0;
}