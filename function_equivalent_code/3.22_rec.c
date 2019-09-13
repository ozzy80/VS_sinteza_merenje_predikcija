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

int f1(int x, int n)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int s = 1;

    int i = 0;
    for (i = 0; i < abs(n); i++) {
	s *= x;
    }

    return s;
}

int function(int x, int n)
{
    int s = 1;

    int i = 0;
    for (i = 0; i < abs(n); i++) {
	s *= x;
    }

    return s;
}


int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
