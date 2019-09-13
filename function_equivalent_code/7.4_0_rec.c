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

int f1(int x)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int i;
    for (i = 0; i <= x; i = i + 1) {
	x += i % 2 == 0 ? 1 : -i;
    }
    return x;
}

int function(int x)
{
    int i;
    for (i = 0; i <= x; i = i + 1) {
	x += i % 2 == 0 ? 1 : -i;
    }
    return x;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
