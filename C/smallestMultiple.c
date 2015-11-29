#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {

    int x = 40;
    while(1) {
        int i;
        for(i=2;i<=20;i++) {
            if(x%i != 0)
                break;
            }
        if(i == 21)
            break;
        x+=20;
        }

    printf("Smallestmultiple %d\n",x);
    }
