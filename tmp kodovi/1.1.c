#include<stdio.h>

int function(int n){
    int ukupno = 0;

    int i = 0;
    while (i < n)
    {
        if(i == 5){
            break;
        }
        ukupno += i;
        i++;  
    }
    return ukupno;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}