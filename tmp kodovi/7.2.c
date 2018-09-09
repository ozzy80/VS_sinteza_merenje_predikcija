#include <stdio.h>
#include <stdlib.h>

void function(int a){
	if (a>5)
		printf("Bigger than 5\n");
	else
		printf("Lesser or equal to 5\n");
	if (a<10)
		printf("Lesser than 10\n");
	else
		printf("Bigger or equal to 10\n"); 
}

int main(){
	int a = 60;
	function(a);
	

	return 0;
}
