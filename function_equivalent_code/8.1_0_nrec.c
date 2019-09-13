#include<stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int n)
{
    helper();
    int ukupno = 0;

    int i = 0;
    while (i < n) {
	if (!(i != 5)) {
	    break;
	}
	ukupno += i;
	i++;
    }
    return ukupno;
}

int function(int n)
{
    int ukupno = 0;

    int i = 0;
    while (i < n) {
	if (!(i != 5)) {
	    break;
	}
	ukupno += i;
	i++;
    }
    return ukupno;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
