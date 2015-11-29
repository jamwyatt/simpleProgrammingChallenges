#include <stdio.h>
#include <stdlib.h>

long *distrib = NULL;
long realstep = -1;
long realmax = -1;

void init(long max, long step) {
    distrib = (long *)malloc((sizeof(long) * ((max/step)))+1);
    realstep = step;
    realmax = max;
    }


void notify(long latency) {
    if(latency > realmax)
        distrib[realmax/realstep]++;
    else
        distrib[latency/realstep]++;
    }

void report_distribution() {
    for(long i=0;i<=(realmax/realstep);i++)
        printf("%ld - %ld\n",i, distrib[i]);
    }



int main(int argc, char *argv[]) {


    init(5*1000, 100);
    notify(1000);
    notify(2000);
    notify(3000);
    notify(4000);
    notify(5000);
    notify(6000);
    notify(7000);
    notify(8000);
    notify(10);

    report_distribution();

    }
