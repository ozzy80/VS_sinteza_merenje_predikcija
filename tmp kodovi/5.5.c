#include <stdio.h>

int function(int a,int b,int c){
    if(a+b+c==17)
        return 2;
    return 3;
}

int main(){
    printf("%d",function(4,6,7));
    return 0;
}