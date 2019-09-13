#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x, int y, int c)
{
    helper();
    if (x <= y && y > c)
	return 2;
    return 3;
}

int function(int x, int y, int c)
{
    if (x <= y && y > c)
	return 2;
    return 3;
}


int main()
{

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
