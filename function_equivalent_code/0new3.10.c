#include<stdio.h>

int function(char *niz){
    int br_v = 0, br_m = 0, br_c = 0, br_b = 0, br_k = 0;

   int i=0;
   while(niz[i] != '\0'){                                      
    if (niz[i]>='A' && niz[i]<='Z'){
        br_v++; 
    } else if (niz[i]>='a' && niz[i]<='z'){
        br_m++;
    }
    else if (niz[i]>='0' && niz[i]<='9'){
        br_c++;
    }
    else if (niz[i]=='\t' || niz[i]=='\n' || niz[i]==' '){
        br_b++;
    }
    br_k;
    i++;    
  }

    return br_v + 3*br_m - 5*br_c + br_b;
}

int f1(char *niz){
    int br_v = 0, br_m = 0, br_c = 0, br_b = 0, br_k = 0;

   int i=0;
   while(niz[i] != '\0'){                                      
    if (niz[i]>='A' && niz[i]<='Z'){
        br_v = br_v+ 1; 
    } else if (niz[i]>='a' && niz[i]<='z'){
        br_m++;
    }
    else if (niz[i]>='0' && niz[i]<='9'){
        br_c++;
    }
    else if (niz[i]=='\t' || niz[i]=='\n' || niz[i]==' '){
        br_b++;
    }
    br_k;
    i++;    
  }

    return br_v + 3*br_m - 5*br_c + br_b;
}

int main(){
    char *niz;
    
    __CPROVER_assert(function(niz) == f1(niz), "greska");

    return 0;
}
