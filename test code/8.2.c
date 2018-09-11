#include<stdio.h>

int function(char *niz){
    int br_v = 0;

   int i=0;
   while(niz[i] != '\0'){
       if (niz[i]>='0' && niz[i]<='9'){
        break; 
    } 
    br_v++;
    i++;    
  }

    return i;
}

int main(){
    
    char *niz;
    __CPROVER_assert(function(niz) == f1(niz), "greska");
    
    return 0;
}