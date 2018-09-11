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
    
    int i=0;
    LOOP:
        if(!(i<n)){
            goto LOOPEND;
        }
        result += x;
        x--;
        i++;
    if(i<n){
        goto LOOP;
    }
    LOOPEND:

    return result;
}

int function(int x){
    int result=0, n = x;
    
    int i=0;
    LOOP:
        if(!(i<n)){
            goto LOOPEND;
        }
        result += x;
        x--;
        i++;
    if(i<n){
        goto LOOP;
    }
    LOOPEND:

    return result;
}


int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}