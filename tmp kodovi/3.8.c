#include<stdio.h>
#include<math.h>

int function(int x){
    int ukupno = 0;

    int i;
    for(i=2;i<=sqrt(x);i++){
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

    return 0;
}