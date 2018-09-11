#include<stdio.h>

int function(int x){
    int ukupno = 0;

    int i;
    for(i=2; i<x; i++){
		if (x%i == 0){
            ukupno += i;
        }
	}
   
    return ukupno;
}

int f1(int x){
    int ukupno = 0;

    int i;
    for(i=2; i<x; i = i+ 1){
		if (x%i == 0){
            ukupno += i;
        }
	}
   
    return ukupno;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
