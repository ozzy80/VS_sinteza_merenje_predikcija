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

int f1()
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int n = 6, t1 = 0, t2 = 1, nextTerm;
    int i = 1;
    while (i <= n) {
	nextTerm = t1 + t2;
	t1 = t2;
	t2 = nextTerm;

	i++;
    }
    return t2;
}

int function()
{
    int n = 6, t1 = 0, t2 = 1, nextTerm;
    int i = 1;
    while (i <= n) {
	nextTerm = t1 + t2;
	t1 = t2;
	t2 = nextTerm;

	i++;
    }
    return t2;
}


int main()
{

    __CPROVER_assert(function() == f1(), "greska");

    return 0;
}
