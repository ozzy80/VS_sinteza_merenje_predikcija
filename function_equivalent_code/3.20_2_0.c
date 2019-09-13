#include <stdio.h>


int function(int x)
{
    int result = 0, n = x;

    int i = 0;
  LOOP:
    if (!(i < n)) {
	goto LOOPEND;
    }
    result += x;
    x = x - 1;
    ;
    i++;
    if (i < n) {
	goto LOOP;
    }
  LOOPEND:

    return result;
}

int f1(int x)
{
    int result = 0, n = x;

    int i = 0;
  LOOP:
    if (!(i < n)) {
	goto LOOPEND;
    }
    result += x;
    x = x - 1;
    ;
    i = i + 1;
    ;
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
