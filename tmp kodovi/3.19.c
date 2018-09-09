#include<stdio.h>

int function(int n){
    int ukupno = 0, j;

    int i;
    for (i = n - 1; 1 == 1;i--){
        for (j = 0; j < n - i + 1; j++){
            ukupno += j;
        }
        for (j = 0; j < 2 * i + 1; j++){
            ukupno -= j;
        }
    if (i == 0)
      break;
  }
  
    return ukupno;
}

int main()
{
    int x = function(10);
    printf("%d\n", x);

    return 0;
}