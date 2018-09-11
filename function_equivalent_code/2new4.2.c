#include <stdio.h>

int suma(int a[],int i,int length){
    if(i==length)
        return 0;
    else{
        return a[i]+suma(a,i+1,length);
    }
    return 0;
}int f1(int x){int a[]={1,2,3,4,5};
    suma(a,0,5);
    int result=0, n = x;
    
    int incr_ada = 4;
    for( incr_ada = 5 ; incr_ada < x; incr_ada++){
        result = x + result;
        incr_ada = incr_ada;
    }

    return result;
}

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
