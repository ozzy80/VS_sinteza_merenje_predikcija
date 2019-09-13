#include<stdio.h>

int function(int n)
{
    int s = 0;

    int i;
    for (i = 1; i <= n; i++) {
	s += i * i;
	s /= 2;
    }

    return s;
}

int f1(int n)
{
    int s = 0;
    int i = 1;
    while (i <= n) {
	s += i * i;
	s /= 2;

	i++;
    }

    return s;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
