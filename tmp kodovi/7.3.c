#include <stdio.h>
#include <stdlib.h>

int function(int a){
	a = a > 3 ? 3 : a;
	return a;
}

int main(){
	int a = 7;
	int b = -1;

	printf("%d\n", function(a));
	printf("%d\n", function(b)); 

	return 0;
}
