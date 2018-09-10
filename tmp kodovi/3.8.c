#include<stdio.h>
#include<math.h>

int function(int x){
    int ukupno = 0;

    int i;
    for(i=2; i<=sqrt(x); i++){
		if (x%i==0){
			if (i==x/i)  
				ukupno += i;
        } else {
            ukupno -= 1;
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