#include <stdio.h>

int function(){
        int n=6, t1 = 0, t2 = 1, nextTerm;

    int i;    
    for (i = 1; i <= n; i++){
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t2;
}
int main()
{
    printf("%d",function());
    printf("%d",f1());

    return 0;
}