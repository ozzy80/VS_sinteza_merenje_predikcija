#include<stdio.h>

int function(int x, int z, int a)
{
    int p = 5, y = 3;

    p = x << z;

    return p;
}

int f1(int x, int z, int a)
{
    int p = 5, y = 3;

    p = x;

    int i_i = 0;

    for (; i_i < z; i_i++) {


	p *= 2;
    }


    return p;
}

int main()
{
    int x, z;
    int y;
    __CPROVER_assert(function(x, y, z) == f1(x, y, z), "greska");

}
