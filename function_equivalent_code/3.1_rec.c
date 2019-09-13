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

int f1(int n)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int tmp = 0;

    int i = 0;
    while (i < n) {
	tmp += 1;
	i++;
    }

    return i;
}

int function(int n)
{
    int tmp = 0;

    int i = 0;
    while (i < n) {
	tmp += 1;
	i++;
    }

    return i;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
