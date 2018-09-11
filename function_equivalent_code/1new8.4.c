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

int f1(int n){
    int an1 = 0, ukupnoProlazaka = 0;

    int an = n;
	while(!(an == 1)){
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

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
