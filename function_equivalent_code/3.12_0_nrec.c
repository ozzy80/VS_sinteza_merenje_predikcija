#include<stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int n)
{
    helper();
    int s = 0;

    int i;
    for (i = 1; i <= n; i = i + 1) {
	s += i * i;
	s /= 2;
    }

    return s;
}

int function(int n)
{
    int s = 0;

    int i;
    for (i = 1; i <= n; i = i + 1) {
	s += i * i;
	s /= 2;
    }

    return s;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}