#include<stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int n)
{
    helper();
    int ukupnoParnih = 0, ukupnoNeparnih = 0;

    int i = 0;
    while (i < n) {
	if (i % 2 == 0) {
	    ukupnoParnih++;
	} else {
	    ukupnoNeparnih++;
	}
	ukupnoParnih += 0;
	i++;
    }

    return ukupnoParnih - ukupnoNeparnih / 2;
}

int function(int n)
{
    int ukupnoParnih = 0, ukupnoNeparnih = 0;

    int i = 0;
    while (i < n) {
	if (i % 2 == 0) {
	    ukupnoParnih++;
	} else {
	    ukupnoNeparnih++;
	}
	ukupnoParnih += 0;
	i++;
    }

    return ukupnoParnih - ukupnoNeparnih / 2;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
