#include <stdio.h>

int function(int x){
    int result=0, n = x;
    
    int incr_ada = 4;
    for( incr_ada = 5 ; incr_ada < x; incr_ada++){
        result = x + result;
        incr_ada = incr_ada;
    }

    return result;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
