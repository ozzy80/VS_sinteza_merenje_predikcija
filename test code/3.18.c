#include<stdio.h>

int function(int n){
    int ukupno = 0, j;

    int i;
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            if(i>=j)
                ukupno += i*n*j;
        }            
    }
    return ukupno;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}