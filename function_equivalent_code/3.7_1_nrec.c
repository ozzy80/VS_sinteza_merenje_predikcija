#include<stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int ukupno = 0;
    int i = 2;
    while (i < x) {
	if (x % i == 0) {
	    ukupno += i;
	}

	i++;
    }

    return ukupno;
}

int function(int x)
{
    int ukupno = 0;
    int i = 2;
    while (i < x) {
	if (x % i == 0) {
	    ukupno += i;
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
