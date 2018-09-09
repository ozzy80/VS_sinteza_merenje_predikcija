#include<stdio.h>

int function(int n){
    int ukupno = 0, j;

    int i;
    for (i=1;i<=n;i++){
        for (j=1; j<=n; j++){
            ukupno += (i-1)*n+j;
        }            
    }
    return ukupno;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}