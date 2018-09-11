  #include <stdio.h>

int suma(int a[],int i,int length){
    if(i==length)
        return 0;
    else{
        return a[i]+suma(a,i+1,length);
    }
    return 0;
}int f1(int x){int a[]={1,2,3,4,5};
    suma(a,0,5);
    int cifra=0;

    int tmp = x;
    while(tmp>0){
      cifra += tmp%10;            
      cifra *= 10;
      tmp /= 10;                
   }
   
   return cifra/10;
}

int function(int x){
    int cifra=0;

    int tmp = x;
    while(tmp>0){
      cifra += tmp%10;            
      cifra *= 10;
      tmp /= 10;                
   }
   
   return cifra/10;
}


int main(){

    int x;
    __CPROVER_assert(function(x) == f1(x), "greska");

    return 0;
}
  