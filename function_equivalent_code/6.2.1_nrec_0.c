#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int function(int x, int y)
{
    helper();

    int aa;

    !(!x && !y) ? (aa = y) : (aa = x);
    return aa;
}



int f1(int x, int y)
{
    helper();

    int aa;


    if (!(!x && !y))
	(aa = y);
    else
	(aa = x);
    return aa;
}

int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
