#include <stdio.h>

int function(int n)
{
    int tmp = 0;

    int i = 0;
    while (i < n) {
	tmp += 1;
	i++;
    }

    return i;
}

int f1(int n)
{
    int tmp = 0;

    int i = 0;
    while (!(i >= n)) {
	tmp += 1;
	i++;
    }

    return i;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
