#include <stdio.h>
#include <stdlib.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    switch (x) {
    case 1:
	return 1;
	break;
    case 2:
	return 2;
	break;
    case 3:
	return 3;
	break;
    case 4:
	return 3;
	break;
    default:
	return 5;
    }
}

int function(int x)
{
    switch (x) {
    case 1:
	return 1;
	break;
    case 2:
	return 2;
	break;
    case 3:
	return 3;
	break;
    case 4:
	return 3;
	break;
    default:
	return 5;
    }
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
