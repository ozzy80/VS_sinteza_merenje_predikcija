#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x, int y)
{
    helper();

    if (x || y) {
	return y;
    } else {
	return x;
    }

    int i = 0;
    int j = 0;
    int aa = 4;
    i++;
    i += 1;
    i--;

    j++;
    j--;

    switch (aa) {
    case 1:
	i += 5;
	break;
    case 2:
	i += 41;
	break;
    case 3:
	i += 74;
	break;
    default:
	i -= 15;
    }
}

int function(int x, int y)
{

    if (x || y) {
	return y;
    } else {
	return x;
    }

    int i = 0;
    int j = 0;
    int aa = 4;
    i++;
    i += 1;
    i--;

    j++;
    j--;

    switch (aa) {
    case 1:
	i += 5;
	break;
    case 2:
	i += 41;
	break;
    case 3:
	i += 74;
	break;
    default:
	i -= 15;
    }
}


int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
