#include <stdio.h>

int condition(int x, int y){
    return (x<y);
    
}

int f(int x, int y){
    return (!(x>=y));
    
}

int main(){

    int x = condition(10, 15);
    printf("%d\n", x);

    return 0;
}
