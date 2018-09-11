#include <stdio.h>
#include <stdlib.h>

void helper(){
    int a=1+2+3;
}int f1(int x){helper();

	if (x % 5 != 2)
		x = f1(x+3);
	else
		x = 0;
	return x;
}

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
