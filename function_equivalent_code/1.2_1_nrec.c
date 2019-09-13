#include <stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1()
{
    helper();
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


int main()
{

    __CPROVER_assert(function() == f1(), "greska");

    return 0;
}
