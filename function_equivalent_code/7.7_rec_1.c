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

int function(int x)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    switch (x) {
    case 1:
	return 1;
	break;
    case 2:
	return 2;
	break;
    case 3:
	return 3;
	break;
    case 4:
	return 3;
	break;
    default:
	return 5;
    }
}



int f1(int x)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    if (x == 1) {
	return 1;
    } else if (x == 2) {
	return 2;
    } else if (x == 3) {
	return 3;
    } else if (x == 4) {
	return 3;
    } else;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
