#include<stdio.h>
#include<math.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int ukupno = 0;

    int i;
    for (i = 2; i <= sqrt(x); i++) {
	if (x % i == 0) {
	    if (i == x / i)
		ukupno += i;
	} else {
	    ukupno -= 1;
	}
    }

    return ukupno;
}

int function(int x)
{
    int ukupno = 0;

    int i;
    for (i = 2; i <= sqrt(x); i++) {
	if (x % i == 0) {
	    if (i == x / i)
		ukupno += i;
	} else {
	    ukupno -= 1;
	}
    }

    return ukupno;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
