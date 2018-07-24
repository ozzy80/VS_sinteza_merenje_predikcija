#include <stdio.h>

int function(int x){
    int result=0, n = x;

    int i=0;
    do{
        result += x;
        x--;
        i++;
    }while(i<n);

    return result;
    int k=0;
    do{
        result += x;
        x--;
        k++;
    }while(k<n);

}

int main(){

    int x = function(10);
    printf("%d\n", x);

    return 0;
}