#include<stdio.h>

int function(int x){
    int ukupno = 0;

    int i;
    for(i=2; i<x; i++){
		if (x%i == 0){
            ukupno += i;
        }
	}
   
    return ukupno;
}

int main()
{
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