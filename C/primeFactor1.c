#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
long n=600851475143L;
long factor=2;
long lastFactor=1;
while(n>1) {
   if(n%factor==0) {
      lastFactor=factor;
      printf("Factor: %ld\n", factor);
      n=n / factor;
      while(n % factor==0) 
         n=n / factor;
      }
   factor=factor+1;
   }

    printf("Largest prime multiple is %ld\n",lastFactor);
    }
