#include<stdio.h>
#include <math.h>


int function(int x)
{
    int ind_nadjen = 0;
    int i = 2;
    while (i <= sqrt(x)) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}

	i++;
    }
    return ind_nadjen;
}

int f1(int x)
{
    int ind_nadjen = 0;
    int i = 2;
    while (!(i > sqrt) (x)) {
	if (x % i == 0) {
	    ind_nadjen = 1;
	    break;
	}

	i++;
    }
    return ind_nadjen;
}

int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
