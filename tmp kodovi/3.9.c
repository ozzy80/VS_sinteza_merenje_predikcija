#include<stdio.h>

int function(int n){
    int an1 = 0, ukupnoProlazaka = 0;

    int an = n;
	while(an != 1){
		if (an%2) {
			an1=(3*an+1)/2;
		}
		else{  
			an1=an/2;
		}
		an=an1; 
        ukupnoProlazaka++;		
	}

    return ukupnoProlazaka;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}