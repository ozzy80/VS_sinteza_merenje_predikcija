#include<stdio.h>

void helper(){
    int a=1+2+3;
}int f1(int n){helper();
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