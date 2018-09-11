#include<stdio.h>

int function(int n){
    int ukupnoParnih = 0, ukupnoNeparnih = 0;

    int i = 0;
    while(i < n){
        if(i%2 == 0){
            ukupnoParnih++;
        }        
        else{
            ukupnoNeparnih++;
        }
        ukupnoParnih += 0;
        i++;  
    }

    return ukupnoParnih - ukupnoNeparnih/2;
}

int f1(int n){
    int ukupnoParnih = 0, ukupnoNeparnih = 0;
int i = 0;
for(;(i < n); 
        i++ )
{
        if(i%2 == 0){
            ukupnoParnih++;
        }        
        else{
            ukupnoNeparnih++;
        }
        ukupnoParnih += 0;
; 
}

    return ukupnoParnih - ukupnoNeparnih/2;
}

int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
