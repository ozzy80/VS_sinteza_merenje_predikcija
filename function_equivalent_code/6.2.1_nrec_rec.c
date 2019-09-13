#include <stdio.h>

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

int f1(int x, int y)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    helper();

    int aa;

    !(!x && !y) ? (aa = y) : (aa = x);
    return aa;
}

int function(int x, int y)
{
    helper();

    int aa;

    !(!x && !y) ? (aa = y) : (aa = x);
    return aa;
}




int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
