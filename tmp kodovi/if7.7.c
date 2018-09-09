#include <stdio.h>
#include <stdlib.h>

int function(int a){
	switch(a){
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		case 4: return 3; break;
		default: return 5;
	}
}

int f1(int a){
	if(a == 1){
   return 1;
}
else if(a == 2){
   return 2;
}
else if(a == 3){
   return 3;
}
else if(a == 4){
   return 3;
}
else {
    return 5;
}
;}

int main(){
	int a = 4;
	printf("%d\n", function(a));

	return 0;
}

