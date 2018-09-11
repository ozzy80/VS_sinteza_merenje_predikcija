#include <stdio.h>
#include <stdlib.h>

void helper(){
    int a=1+2+3;
}int f1(int x){helper();
	int u;
	if (x>5)
		u = 84;
	else
		u = 35;
	return u + x;
}

int function(int x){
	int u;
	if (x>5)
		u = 84;
	else
		u = 35;
	return u + x;
}


int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

	return 0;
}
