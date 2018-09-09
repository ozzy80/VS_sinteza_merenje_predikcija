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

void f1(int a){
	
switch(a){
case 7: printf("seven\n"); break;
case 6: printf("six\n"); break;
default: printf("something else\n");
}
}

int main(){
	int a[3] = {7, 6, 10};
	int i;
	
	for (i = 0; i < 3; i++)
		function(a[i]);
	

	return 0;
}

