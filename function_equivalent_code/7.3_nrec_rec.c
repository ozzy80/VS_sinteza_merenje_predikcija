#include <stdio.h>
#include <stdlib.h>

void helper()
{
    int a = 1 + 2 + 3;
}

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
    helper();
    int b = 8;
    x > 3 ? x = 3 : x;
    return x + b;
}

int function(int x)
{
    helper();
    int b = 8;
    x > 3 ? x = 3 : x;
    return x + b;
}




int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
