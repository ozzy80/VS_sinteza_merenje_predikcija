#include <stdio.h>
#include <math.h>

int function(int x, int n){
    int x_desetica = 0, max_desetica=0;

    int i;
	for(i=0; i<n; i++){
		x_desetica = (abs(x)/10)%10;
		
		if(x_desetica > max_desetica){
			max_desetica = x_desetica;
		}
        x = x/10;
	}

    return max_desetica;
}

int main()
{
    int x = function(10, 15);
    printf("%d\n", x);
    int y = f1(10, 15);
    printf("%d\n", y);

    x = function(52, 15);
    printf("%d\n", x);
    y = f1(52, 15);
    printf("%d\n", y);

    x = function(34, 15);
    printf("%d\n", x);
    y = f1(34, 15);
    printf("%d\n", y);

    x = function(525, 15);
    printf("%d\n", x);
    y = f1(525, 15);
    printf("%d\n", y);

    return 0;
}