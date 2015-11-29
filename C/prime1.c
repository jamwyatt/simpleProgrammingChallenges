#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isprime(long i) {
    if(i%2==0 || i%3==0 || i%5==0)
        return 0;
    for(long x=6;x<(i/2);x++)
        if(i%x == 0)
            return 0;       // False
    return 1;               // true
    }


int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr,"Error: provide a target integer parameter\n");
        exit(-1);
        }
    long target = atol(argv[1]);
    if(target < 10) {
        fprintf(stderr,"Error: give a target greater than 10\n");
        exit(-1);
        }

    if(isprime(target))
        printf("%ld is prime\n", target);
    else
        printf("%ld is NOT prime\n", target);
    }
