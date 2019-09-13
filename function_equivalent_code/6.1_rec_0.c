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

int function(int x, int y)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int n = 0, g = 1;

    if (!(!x && !y)) {
	x++;
	g--;
    } else if (x && !y) {
	x--;
	return x;
    } else {
	g++;
	return y;
    }

    x += 1;

    return x + g;
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

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
