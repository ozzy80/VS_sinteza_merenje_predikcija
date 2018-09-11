#include <stdio.h>
#include <stdlib.h>

int function(int x){
	int u;
	if (x>5)
		u = 84;
	else
		u = 35;
	return u + x;
}

int f1(int x){
	int u;
	
((x>5)) ? (u = 84) : (u = 35);return u + x;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

	return 0;
}

