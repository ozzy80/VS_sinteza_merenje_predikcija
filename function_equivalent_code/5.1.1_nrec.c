#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x, int y)
{
    helper();
    return (x || y);

}

int function(int x, int y)
{
    return (x || y);

}


int main()
{

    int x, y;
    __CPROVER_assert(function(x, y) == f1(x, y), "greska");

    return 0;
}
