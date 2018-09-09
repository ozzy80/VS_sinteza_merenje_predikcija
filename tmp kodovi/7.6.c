#include <stdio.h>
#include <stdlib.h>

void function(char* s){
	char* tmp;
	for (tmp = s; *tmp != '\0'; s++)
		if (*tmp == 'a')
			*tmp = 'e';
		else if (*tmp == 'e')
			*tmp = 'i';
		else if (*tmp == 'i')
			*tmp = 'o';
		else if (*tmp == 'o')
			*tmp = 'u'; 
}

int main(){
	char* s = "eholalija";
	function(s);
	printf("%s\n", s);

	return 0;
}
