#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int function(int x)
{
    helper();
    int f = 1;

    int i = 1;
    while (i < x) {
	if (i > 12)
	    break;
	f *= i;
	i++;
    }
    return f;
}



int f1(int x)
{
    helper();
    int f = 1;
    int i = 1;
    for (; (i < x); i++) {
	if (i > 12)
	    break;
	f *= i;
	;
    }
    return f;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
