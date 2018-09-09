#include <stdio.h>
#include <stdlib.h>

int function(int a){
	int b = 8;
	a > 3 ? a = 3 : a;
	return a+b;
}

int main(){
	int a = 7;
	int b = -1;

	printf("%d\n", function(a));
	printf("%d\n", function(b)); 

	return 0;
}
