#include <stdio.h>
#include <stdlib.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int function(int x)
{
    helper();
    int u;
    if (x > 5)
	u = 84;
    else
	u = 35;
    return u + x;
}



int f1(int x)
{
    helper();
    int u;

    ((x > 5)) ? (u = 84) : (u = 35);
    return u + x;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
