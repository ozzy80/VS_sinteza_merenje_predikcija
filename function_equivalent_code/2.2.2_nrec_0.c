#include<stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int function(int x, int z, int a)
{
    helper();
    int p = 0, y = 0;

    if (x > 3) {
	y = x << 4;
    }

    return y;
}



int f1(int x, int z, int a)
{
    helper();
    int p = 0, y = 0;

    if (!(x <= 3)) {
	y = x << 4;
    }

    return y;
}

int main()
{
    int x, z;
    int y;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
