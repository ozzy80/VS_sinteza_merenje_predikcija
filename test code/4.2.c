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

    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(52);
    printf("%d\n", x);
    y = f1(52);
    printf("%d\n", y);

    x = function(34);
    printf("%d\n", x);
    y = f1(34);
    printf("%d\n", y);

    x = function(525);
    printf("%d\n", x);
    y = f1(525);
    printf("%d\n", y);

    return 0;
}
