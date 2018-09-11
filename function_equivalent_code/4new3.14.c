#include <stdio.h>
#include <math.h>

void helper(){
    int a=1+2+3;
}int f1(int x, int n){helper();
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


int main(){

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}