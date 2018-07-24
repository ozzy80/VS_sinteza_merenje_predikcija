#include <stdio.h>

int function(int x){
    int result=0, n = x;
    
    int incr_ada = 4;
    for( incr_ada = 5 ; incr_ada < x; incr_ada++){
        result = x + result;
        incr_ada = incr_ada;
    }
}

int main(){

    int x = function(40);
    printf("%d\n", x);

    return 0;
}
