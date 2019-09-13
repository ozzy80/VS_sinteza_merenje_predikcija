#include <stdio.h>

void helper()
{
    int a = 1 + 2 + 3;
}

int f1(int x)
{
    helper();
    int result = 0, n = x;

    int i = 0;
  LOOP:
    if (!(i < n)) {
	goto LOOPEND;
    }
    result += x;
    x--;
    i++;
    if (i < n) {
	goto LOOP;
    }
  LOOPEND:

    return result;
}

int function(int x)
{
    int result = 0, n = x;

    int i = 0;
  LOOP:
    if (!(i < n)) {
	goto LOOPEND;
    }
    result += x;
    x--;
    i++;
    if (i < n) {
	goto LOOP;
    }
  LOOPEND:

    return result;
}


int main()
{

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
