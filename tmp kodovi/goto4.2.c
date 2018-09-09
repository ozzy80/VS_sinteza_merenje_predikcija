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

int f1(int x){
    int result=0, n = x;
    
int  incr_ada = 5;

LOOP:
if(!(incr_ada < x)){
   goto LOOPEND;
}
{
        result = x + result;
        incr_ada = incr_ada;
    
incr_ada++;

if(incr_ada < x){
   goto LOOP;
}
;
}
LOOPEND:

    return result;
}

int main(){

    int x = function(40);
    printf("%d\n", x);

    return 0;
}

