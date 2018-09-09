#include <stdio.h>

int function(int a,int b){
    if(a && b)
        return a;
    return b;
}

int main(){
    printf("%d",function(1,0));
    return 0;
}