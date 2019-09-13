#include <stdio.h>
#include <stdlib.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int i;
    for (i = 0; i <= x; i = i + 1) {
	x += i % 2 == 0 ? 1 : -i;
    }
    return x;
}

int function(int x)
{
    int i;
    for (i = 0; i <= x; i = i + 1) {
	x += i % 2 == 0 ? 1 : -i;
    }
    return x;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
