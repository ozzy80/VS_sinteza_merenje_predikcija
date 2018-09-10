#include <stdio.h>
#include <stdlib.h>

int function(int x){
	int b = 8;
	x > 3 ? x = 3 : x;
	return x+b;
}

int main(){
    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(52);
    printf("%d\n", x);
    y = f1(52);
    printf("%d\n", y);

    x = function(34);
    printf("%d\n", x);
    y = f1(34);
    printf("%d\n", y);

    x = function(525);
    printf("%d\n", x);
    y = f1(525);
    printf("%d\n", y);

	return 0;
}
