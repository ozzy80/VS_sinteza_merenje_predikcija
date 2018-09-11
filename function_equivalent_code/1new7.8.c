#include <stdio.h>
#include <stdlib.h>

int suma(int a[],int i,int length){
    if(i==length)
        return 0;
    else{
        return a[i]+suma(a,i+1,length);
    }
    return 0;
}int f1(char c){int a[]={1,2,3,4,5};
    suma(a,0,5);
	int x;

	switch(c){
		case 'b': x = 7; break;
	        case 'z': x -= 3; break;
	        case 'r': return 308; break;
	        case 'c': x = 9; break;
	} 

	return x-6;

}

int function(char c){
	int x;

	switch(c){
		case 'b': x = 7; break;
	        case 'z': x -= 3; break;
	        case 'r': return 308; break;
	        case 'c': x = 9; break;
	} 

	return x-6;

}


int main(){
	
	char c;
    __CPROVER_assert(function(c) == f1(c), "greska");

	return 0;
}
