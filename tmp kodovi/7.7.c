#include <stdio.h>
#include <stdlib.h>

int function(int a){
	switch(a){
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		case 4: return 3; break;
		default: return 5;
	}
}

int main(){
	int a = 4;
	printf("%d\n", function(a));

	return 0;
}
