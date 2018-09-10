  #include <stdio.h>

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

    int x = function(10);
    printf("%d\n", x);
    int y = f1(10);
    printf("%d\n", y);

    x = function(52);
    printf("%d\n", x);
    y = f1(52);
    printf("%d\n", y);

    x = function(34);
    printf("%d\n", x);
    y = f1(34);
    printf("%d\n", y);

    x = function(525);
    printf("%d\n", x);
    y = f1(525);
    printf("%d\n", y);

    return 0;
}
  