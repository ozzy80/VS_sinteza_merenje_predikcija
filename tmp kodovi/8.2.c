#include<stdio.h>

int function(char *niz){
    int br_v = 0;

   int i=0;
   while(niz[i] != '\0'){                                      
    if (niz[i]>='0' && niz[i]<='9'){
        break; 
    } 
    i++;    
  }

    return i;
}

int main()
{
    char niz[] = "Hello9 WORLd !";
    int x = function(niz);
    printf("%d\n", x);

    return 0;
}