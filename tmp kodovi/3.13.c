#include<stdio.h>
#include <math.h>

int function(int x){
    int ind_nadjen = 0;

    int i;
	for(i=2; i<=sqrt(x); i++){
		if (x%i==0){
            ind_nadjen = 1;
            break;
        }
	}
    return ind_nadjen;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}