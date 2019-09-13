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

int f1(int x, int z, int a)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int p = 0, y = 0;

    if (x > 3) {
	y = x << 4;
    }

    return y;
}

int function(int x, int z, int a)
{
    int p = 0, y = 0;

    if (x > 3) {
	y = x << 4;
    }

    return y;
}


int main()
{
    int x, z;
    int y;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
