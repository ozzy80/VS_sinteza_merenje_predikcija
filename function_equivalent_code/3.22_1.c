#include<stdio.h>

int function(int x, int n)
{
    int s = 1;

    int i = 0;
    for (i = 0; i < abs(n); i++) {
	s *= x;
    }

    return s;
}

int f1(int x, int n)
{
    int s = 1;
    int i = 0;
    while (i < abs(n)) {
	s *= x;

	i++;
    }

    return s;
}

int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
