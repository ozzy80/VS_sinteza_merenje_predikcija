#include <stdio.h>

int function(int a,int b,int c){
    if(a+b!=-17)
        return 6;
    return 8;
}

int main(){
    printf("%d",function(4,6,7));
    return 0;
}