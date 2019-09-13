#include <stdio.h>
#include <stdlib.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int b = 8;

    if (x > 3)
	x = 3;
    else
	x;
    return x + b;
}

int function(int x)
{
    int b = 8;

    if (x > 3)
	x = 3;
    else
	x;
    return x + b;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
