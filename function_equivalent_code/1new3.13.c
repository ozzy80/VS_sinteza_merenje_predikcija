#include<stdio.h>
#include <math.h>

int function(int x){
    int ind_nadjen = 0;

    int i;
	for(i=2; i<=sqrt(x); i++){
		if (x%i==0){
            ind_nadjen = 1;
            break;
        }
	}
    return ind_nadjen;
}

int f1(int x){
    int ind_nadjen = 0;

    int i;
	for(i=2; i<=sqrt(x); i = i+ 1){
		if (x%i==0){
            ind_nadjen = 1;
            break;
        }
	}
    return ind_nadjen;
}

int main(){
 
    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
