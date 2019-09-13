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

float function(float x)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    float p = 0, y = 84;
    p = x * y;

    return p;
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
    float y;
    __CPROVER_assert(function(y) == f1(y), "greska");


    return 0;
}
