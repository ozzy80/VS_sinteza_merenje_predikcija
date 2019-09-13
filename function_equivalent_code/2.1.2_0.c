#include<stdio.h>

int function(int x)
{
    int p = 0, y = 84;
    p = x / y;

    return p;
}

int f1(int x)
{
    int p = 0, y = 84;
    while (x - y > 0) {
	p++;
	x = x - y;

	;
    }


    return p;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(52);
    printf("%d\n", x);
    y = f1(52);
    printf("%d\n", y);

    x = function(34);
    printf("%d\n", x);
    y = f1(34);
    printf("%d\n", y);

    x = function(525);
    printf("%d\n", x);
    y = f1(525);
    printf("%d\n", y);

    return 0;
}
