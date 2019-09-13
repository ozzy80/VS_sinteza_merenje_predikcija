#include<stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x, int z, int a)
{
    helper();
    int p = 5, y = 3;

    p = x << z;

    return p;
}

int function(int x, int z, int a)
{
    int p = 5, y = 3;

    p = x << z;

    return p;
}


int main()
{
    int x, z;
    int y;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
