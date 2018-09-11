#include <stdio.h>
#include <stdlib.h>

int function(int x){
	int b = 8;
	x > 3 ? x = 3 : x;
	return x+b;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

	return 0;
}
