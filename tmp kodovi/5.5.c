#include <stdio.h>

int function(int a,int b,int c){
    int l=a+b+c;
    if(l==17)
        return 2;
    return 3;
}

int main(){
    printf("%d",function(4,6,7));
    return 0;
}