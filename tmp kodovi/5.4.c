#include <stdio.h>

int function(int a,int b,int c){
    int k = a+b<3;
    if(k>=c)
        return 2;
    return 3;
}

int main(){
    printf("%d",function(4,6,7));
    return 0;
}