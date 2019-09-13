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

int f1(char *niz)
{
    int a[] = { 1, 2, 3, 4, 5 };
    suma(a, 0, 5);
    int br_v = 0;

    int i = 0;
    while (niz[i] != '\0') {
	if (niz[i] >= '0' && niz[i] <= '9') {
	    break;
	}
	br_v++;
	i++;
    }

    return i;
}

int function(char *niz)
{
    int br_v = 0;

    int i = 0;
    while (niz[i] != '\0') {
	if (niz[i] >= '0' && niz[i] <= '9') {
	    break;
	}
	br_v++;
	i++;
    }

    return i;
}


int main()
{

    char *niz;
    __CPROVER_assert(function(niz) == f1(niz), "greska");

    return 0;
}
