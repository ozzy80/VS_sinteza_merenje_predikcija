#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int function(int x)
{
    helper();
    int result = 0, n = x;

    int i = 0;
    while (i < n) {
	result += x;
	x--;
	i++;
    }

    return result;
}



int f1(int x)
{
    helper();
    int result = 0, n = x;

    int i = 0;
    while (!(i >= n)) {
	result += x;
	x--;
	i++;
    }

    return result;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
