#include<stdio.h>
#include <math.h>


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
    int ind_nadjen = 0;
    int i = 2;
    while (i <= sqrt(x)) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}

	i++;
    }
    return ind_nadjen;
}

int function(int x)
{
    int ind_nadjen = 0;
    int i = 2;
    while (i <= sqrt(x)) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}

	i++;
    }
    return ind_nadjen;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
