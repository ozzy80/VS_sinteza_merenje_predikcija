#include <stdio.h>

int function(int x, int y){
    
    int aa;
    
    !(!x && !y) ? (aa = y) : (aa = x);
    return aa;
}

int f1(int x, int y){
    
    int aa;
    
    
if (!(!x && !y))
   (aa = y);
else
   (aa = x);
    return aa;
}

int main(){

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
