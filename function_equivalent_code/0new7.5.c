#include <stdio.h>
#include <stdlib.h>

int function(int x){
	if (x == 7){
		return 9;
	}
    else if (x == 6){
		return 15;
	}
    else{
		return 0;
	}
}

int f1(int x){
	if (!(x != 7)){
		return 9;
	}
    else if (x == 6){
		return 15;
	}
    else{
		return 0;
	}
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");
	
	return 0;
}

