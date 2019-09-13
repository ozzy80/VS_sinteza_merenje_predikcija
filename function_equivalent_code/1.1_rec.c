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

int f1(int n)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int ukupno = 0;

    int i = 0;
    while (i < n) {
	if (i == 5) {
	    break;
	}
	ukupno += i;
	i++;
    }
    return ukupno;
}

int function(int n)
{
    int ukupno = 0;

    int i = 0;
    while (i < n) {
	if (i == 5) {
	    break;
	}
	ukupno += i;
	i++;
    }
    return ukupno;
}


int main()
{
    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
