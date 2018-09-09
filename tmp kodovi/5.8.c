#include <stdio.h>

int function(int a,int b){
    if(a && !b)
        return 2;
    return 1;
}

int main(){
    printf("%d",function(1,0));
    return 0;
}