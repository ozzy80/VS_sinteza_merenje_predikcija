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

float f1(float x, int z, float a)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    float p = 0, y = 84;
    int as = 43;

    p = x * z;

    return p;
}

float function(float x, int z, float a)
{
    float p = 0, y = 84;
    int as = 43;

    p = x * z;

    return p;
}


int main()
{
    float x, z;
    int y;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
