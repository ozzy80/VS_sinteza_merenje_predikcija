#include<stdio.h>
#include <math.h>

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
    int ind_nadjen = 0;

    int i;
    for (i = 2; i <= sqrt(x); i++) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}
    }
    return ind_nadjen;
}

int function(int x)
{
    helper();
    int ind_nadjen = 0;

    int i;
    for (i = 2; i <= sqrt(x); i++) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}
    }
    return ind_nadjen;
}




int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
