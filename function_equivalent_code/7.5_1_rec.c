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
    if (!(x != 7)) {
	return 9;
    } else if (x == 6) {
	return 15;
    } else {
	return 0;
    }
}

int function(int x)
{
    if (!(x != 7)) {
	return 9;
    } else if (x == 6) {
	return 15;
    } else {
	return 0;
    }
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
