#include <stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int result = 0, n = x;

    int incr_ada = 5;
    while (incr_ada < x) {
	result = x + result;
	incr_ada = incr_ada;

	incr_ada++;
    }

    return result;
}

int function(int x)
{
    int result = 0, n = x;

    int incr_ada = 5;
    while (incr_ada < x) {
	result = x + result;
	incr_ada = incr_ada;

	incr_ada++;
    }

    return result;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
