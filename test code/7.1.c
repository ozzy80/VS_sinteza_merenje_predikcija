#include <stdio.h>
#include <stdlib.h>

int function(int x){

	if (x % 5 != 2)
		x = function(x+3);
	else
		x = 0;
	return x;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

	return 0;
}
