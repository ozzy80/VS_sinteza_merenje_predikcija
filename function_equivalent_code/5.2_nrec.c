#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x, int y)
{
    helper();
    if (x > y)
	return x;
    else
	return y;
}

int function(int x, int y)
{
    if (x > y)
	return x;
    else
	return y;
}


int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
