#include <stdio.h>
#include <stdlib.h>

int suma(int a[], int i, int length)
{
    if (i == length)
	return 0;
    else {
	return a[i] + suma(a, i + 1, length);
    }
    return 0;
}

int function(int x)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);

    if (x % 5 != 2)
	x = f1(x + 3);
    else
	x = 0;
    return x;
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

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
