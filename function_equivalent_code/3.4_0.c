#include <stdio.h>

int function(int x)
{
    int cifra = 0;

    int tmp = x;
    while (tmp > 0) {
	cifra += tmp % 10;
	cifra *= 10;
	tmp /= 10;
    }

    return cifra / 10;
}

int f1(int x)
{
    int cifra = 0;

    int tmp = x;
    while (!(tmp <= 0)) {
	cifra += tmp % 10;
	cifra *= 10;
	tmp /= 10;
    }

    return cifra / 10;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
