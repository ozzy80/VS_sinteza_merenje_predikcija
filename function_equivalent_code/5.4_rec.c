#include <stdio.h>

int suma(int a[], int i, int length)
{
    if (i == length)
	return 0;
    else {
	return a[i] + suma(a, i + 1, length);
    }
    return 0;
}

int f1(int x, int y, int c)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int k = x + y < 3;
    if (k >= c)
	return 2;
    return 3;
}

int function(int x, int y, int c)
{
    int k = x + y < 3;
    if (k >= c)
	return 2;
    return 3;
}


int main()
{

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
