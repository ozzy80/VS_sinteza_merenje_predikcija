#include <stdio.h>

int function(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(){
    printf("%d",function(4,6));
    return 0;
}