#include <stdio.h>
#include <stdlib.h>

int function(char c){
	int a;

	switch(c){
		case 'b': a = 7; break;
	        case 'z': printf("zzzzzz\n"); break;
	        case 'r': return 308; break;
	        case 'c': a = 9; break;
	} 

	return a-6;

}

int main(){
	char c = 'c';
	printf("%d\n", function(c));

	return 0;
}
