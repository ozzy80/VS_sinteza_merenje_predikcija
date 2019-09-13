#include <stdio.h>

int function(int x, int y)
{
    int n = 0, g = 1;

    if (!(!x && !y)) {
	x++;
	g--;
    } else if (x && !y) {
	x--;
	return x;
    } else {
	g++;
	return y;
    }

    x += 1;

    return x + g;
}

int f1(int x, int y)
{
    int n = 0, g = 1;

    if (!(!x && !y)) {
	x = x + 1;
	;
	g--;
    } else if (x && !y) {
	x--;
	return x;
    } else {
	g++;
	return y;
    }

    x += 1;

    return x + g;
}

int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
