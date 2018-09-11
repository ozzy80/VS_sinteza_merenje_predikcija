#include <stdio.h>
#include <stdlib.h>

int function(char c){
	int x;

	switch(c){
		case 'b': x = 7; break;
	        case 'z': x -= 3; break;
	        case 'r': return 308; break;
	        case 'c': x = 9; break;
	} 

	return x-6;

}

int f1(char c){
	int x;

	;

	return x-6;

}

int main(){
	
	char c;
    __CPROVER_assert(function(c) == f1(c), "greska");

	return 0;
}

