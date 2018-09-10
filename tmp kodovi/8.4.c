#include<stdio.h>

int function(int n){
    int an1 = 0, ukupnoProlazaka = 0;

    int an = n;
	while(an != 1){
		if (an%2) {
			an1=(2*an+1)/2;
		}
		else{  
			break;
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

    return 0;
}