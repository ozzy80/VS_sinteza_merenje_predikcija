#include <stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int f = 1;
    int i = 1;
    for (; (i < x); i++) {
	f = f * i;
	;
    }
    return f;
}

int function(int x)
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
