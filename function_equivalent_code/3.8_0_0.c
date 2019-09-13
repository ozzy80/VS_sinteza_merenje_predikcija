#include<stdio.h>
#include<math.h>


int function(int x)
{
    int ukupno = 0;

    int i;
    for (i = 2; i <= sqrt(x); i = i + 1) {
	if (x % i == 0) {
	    if (i == x / i)
		ukupno += i;
	} else {
	    ukupno -= 1;
	}
    }

    return ukupno;
}

int f1(int x)
{
    int ukupno = 0;
    int i = 2;
    while (i <= sqrt(x)) {
	if (x % i == 0) {
	    if (i == x / i)
		ukupno += i;
	} else {
	    ukupno -= 1;
	}

	i = i + 1);
    }

    return ukupno;
}

int main() {

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
