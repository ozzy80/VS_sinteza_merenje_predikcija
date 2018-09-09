#include <stdio.h>
#include <stdlib.h>

int function(int a){

	if (a % 5 != 4)
		a = function(a+5);
	else
		a = 0; 

	return a;
}

int f1(int a){

	
((a % 5 != 4)) ? (a = f1(a+5)) : (a = 0);
}

int main(){
	int a = 7;
	printf("%d\n", function(a));

	return 0;
}

