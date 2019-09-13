#include<stdio.h>


void helper()
{
    int a = 1 + 2 + 3;
}

int f1(char *niz)
{
    helper();
    int br_v = 0;

    int i = 0;
    while (niz[i] != '\0') {
	if (niz[i] >= '0' && niz[i] <= '9') {
	    break;
	}
	br_v = br_v + 1;
	i++;
    }

    return i;
}

int function(char *niz)
{
    int br_v = 0;

    int i = 0;
    while (niz[i] != '\0') {
	if (niz[i] >= '0' && niz[i] <= '9') {
	    break;
	}
	br_v = br_v + 1;
	i++;
    }

    return i;
}


int main()
{

    char *niz;
    __CPROVER_assert(function(niz) == f1(niz), "greska");

    return 0;
}
