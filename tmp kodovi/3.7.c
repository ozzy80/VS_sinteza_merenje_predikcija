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

    return 0;
}