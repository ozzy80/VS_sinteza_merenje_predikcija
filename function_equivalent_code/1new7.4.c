#include <stdio.h>
#include <stdlib.h>

int function(int x){
	int i;
	for (i = 0; i <= x; i++){
		x += i % 2 == 0 ? 1 : -i;
	} 
	return x;
}

int f1(int x){
	int i;
	for (i = 0; i <= x; i = i+ 1){
		x += i % 2 == 0 ? 1 : -i;
	} 
	return x;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

	return 0;
}

