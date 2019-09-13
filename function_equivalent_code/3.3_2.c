#include <stdio.h>

int function(int x)
{
    int f = 1;

    int i = 1;
    while (i < x) {
	f = f * i;
	i++;
    }
    return f;
}

int f1(int x)
{
    int f = 1;
    int i = 1;
    for (; (i < x); i++) {
	f = f * i;
	;
    }
    return f;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
