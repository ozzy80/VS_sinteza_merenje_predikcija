#include <stdio.h>

int function(int x, int y, int c)
{
    int l = x + y + c;
    if (l == 17)
	return 2;
    return 3;
}

int f1(int x, int y, int c)
{
    int l = x + y + c;
    if (!(l != 17))
	return 2;
    return 3;
}

int main()
{

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
