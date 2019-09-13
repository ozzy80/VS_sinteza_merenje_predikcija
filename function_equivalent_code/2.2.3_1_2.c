#include<stdio.h>


int function(int n)
{
    int s = 2;
    int i = 1;
    while (i <= n) {
	if (i <= 3) {
	    s = s << i;
	}

	i++;
    }

    return s;
}

int f1(int n)
{
    int s = 2;
    int i = 1;
for (; (i <= n);}

     int main() {

     int x; __CPROVER_assert(function(x) == f1(x), "greska"); return 0;}
