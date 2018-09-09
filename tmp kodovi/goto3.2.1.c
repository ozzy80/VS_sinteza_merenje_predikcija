#include <stdio.h>

int function(int x){
    int result=0, n = x;

    int i=0;
    while(i<n){
        result += x;
        x--;
        i++;
    }

    return result;
}

int f1(int x){
    int result=0, n = x;
int i=0;
LOOP:
if(!((i<n))){
   goto LOOPEND;
}
{
        result += x;
        x--;


        i++;

if((i<n)){
   goto LOOP;
}
;
}
LOOPEND:

    return result;
}

int main(){

    int x = function(10);
    printf("%d\n", x);

    return 0;
}
