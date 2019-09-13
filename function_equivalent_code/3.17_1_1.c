#include<stdio.h>


int function(int n)
{
    int ukupno = 0, j;
    int i = 1;
    while (i <= n) {
	for (j = 1; j <= n; j++) {
	    ukupno += i * n * j;
	}

	i++;
    }
    return ukupno;
}

int f1(int n)
{
    int ukupno = 0, j;
    int i = 1;
    while (!(i > n)) {
	for (j = 1; j <= n; j++) {
	    ukupno += i * n * j;
	}

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
