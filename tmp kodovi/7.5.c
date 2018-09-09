#include <stdio.h>
#include <stdlib.h>

void function(int a){
	if (a == 7){
		printf("seven\n");
	}
        else if (a == 6){
		printf("six\n");
	}
        else{
		printf("something else\n");
	}
}

int main(){
	int a[3] = {7, 6, 10};
	int i;
	
	for (i = 0; i < 3; i++)
		function(a[i]);
	

	return 0;
}
