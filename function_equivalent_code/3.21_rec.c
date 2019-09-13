#include<stdio.h>

int suma(int a[], int i, int length)
{
    if (i == length)
	return 0;
    else {
	return a[i] + suma(a, i + 1, length);
    }
    return 0;
}

int f1(int x1, int x2)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int r = 1;

    int x = x1;
    int y = x2;
    while (y) {
	r = x % y;
	x = y;
	y = r;
    }
    return x;
}

int function(int x1, int x2)
{
    int r = 1;

    int x = x1;
    int y = x2;
    while (y) {
	r = x % y;
	x = y;
	y = r;
    }
    return x;
}


int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
