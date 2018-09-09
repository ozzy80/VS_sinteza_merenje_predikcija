#include <stdio.h>

int condition(int x, int y){
    int n=0, a=1;

    if(!(!x && !y)){
        if(x == n){
            x++;
            a--;
        }
        else if(x + 1 == n){
            x--;
            a++;
        }
        else{
            x++;
            a++;
        }
        return y;
    } 
    else if(x && !y){
        return x;
    }
    else if(x || y){
        return y;
    }  else if(!x || y){
        return x;
    }  else{
        return y;
    }
   
    x += 1;
    
    return !(!x && !y) ? y : x;
}

int main(){

    int x = condition(0, 0);
    printf("%d\n", x);

    return 0;
}