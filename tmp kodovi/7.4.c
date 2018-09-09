#include <stdio.h>
#include <stdlib.h>

int function(int a){
	int i;
	for (i = 0; i <= a; i++)
		a += i % 2 == 0 ? 1 : -i; 
	return a;
}

int main(){
	int a = 100;
	printf("%d\n", function(a));

	return 0;
}
