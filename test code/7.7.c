#include <stdio.h>
#include <stdlib.h>

int function(int x){
	switch(x){
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		case 4: return 3; break;
		default: return 5;
	}
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
