#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int sum = 0;
    int count = 0;
    for(int x=3;x<1000;x++) {
        if((x%3==0) || (x%5==0)) {
            sum += x;
            printf("%d ", x);
            count++;
            }
        }
    printf("Sum of Multiples of 3 or 5 below 1000 is %d from %d multiples\n",sum, count);
    }
