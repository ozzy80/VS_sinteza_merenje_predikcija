#include <stdio.h>
#include <math.h>


int function(int x, int n)
{
    int x_desetica = 0, max_desetica = 0;

    int i;
    for (i = 0; i < n; i++) {
	x_desetica = (abs(x) / 10) % 10;

	if (!(x_desetica <= max_desetica)) {
	    max_desetica = x_desetica;
	}
	x = x / 10;
    }

    return max_desetica;
}

int f1(int x, int n)
{
    int x_desetica = 0, max_desetica = 0;

    int i;
    for (i = 0; i < n; i = i + 1) {
	x_desetica = (abs(x) / 10) % 10;

	if (!(x_desetica <= max_desetica)) {
	    max_desetica = x_desetica;
	}
	x = x / 10;
    }

    return max_desetica;
}

int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
