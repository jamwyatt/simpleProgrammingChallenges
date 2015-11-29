#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int prevprev = -1;
    int prev = 0;
    int fib = 1;
    int evensum = 0;
    int evenfib = 0;
    while(fib < (4*1000*1000)){
        if(fib%2 == 0) {
            evensum += fib;
            evenfib = fib;
            printf("Even Fib: %d\n", fib);
            }
        prevprev = prev;
        prev = fib;
        fib = prevprev + prev;
        }
    printf("Last fibonacci number is %d and last even fibonacci number is %d\n",fib, evenfib);
    printf("Sum of even Fibonacci numbers below 4000000 is %d\n",evensum);
    }
