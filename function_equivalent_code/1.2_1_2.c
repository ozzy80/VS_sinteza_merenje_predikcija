#include <stdio.h>


int function()
{
    int n = 6, t1 = 0, t2 = 1, nextTerm;
    int i = 1;
    while (i <= n) {
	nextTerm = t1 + t2;
	t1 = t2;
	t2 = nextTerm;

	i++;
    }
    return t2;
}

int f1()
{
    int n = 6, t1 = 0, t2 = 1, nextTerm;
    int i = 1;
    for (; (i <= n); i++) {
	nextTerm = t1 + t2;
	t1 = t2;
	t2 = nextTerm;
	;
    }
    return t2;
}

int main()
{

    __CPROVER_assert(function() == f1(), "greska");

    return 0;
}
