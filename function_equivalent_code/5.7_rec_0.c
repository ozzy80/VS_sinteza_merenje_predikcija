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

int function(int x, int y, int c)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    if (x || y)
	return c;
    return 8;
}



int f1(int a[], int i, int length)
{
    if (!(i != length))
	return 0;
    else {
	return a[i] + f1(a, i + 1, length);
    }
    return 0;
}

int main()
{

    int x, y, z;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

    return 0;
}
