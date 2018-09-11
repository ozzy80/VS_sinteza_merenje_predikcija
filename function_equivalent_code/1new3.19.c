#include<stdio.h>

int function(int n){
    int ukupno = 0, j;

    int i;
    for (i = n - 1; 1 == 1; i--){
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

int f1(int n){
    int ukupno = 0, j;
int i = n - 1;
while(1 == 1){
        for (j = 0; j < n - i + 1; j++){
            ukupno += j;
        }
        for (j = 0; j < 2 * i + 1; j++){
            ukupno -= j;
        }
    if (i == 0)
      break;
  
i--;
}
  
    return ukupno;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
