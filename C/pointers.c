#include <stdio.h>

typedef struct foo {
        int a;
        char b;
        long c;
        } MyStruct;


int main(int argc, char *argv[]) {

    for(int x=0;x<argc;x++)
        printf("Arg[%d]=%s\n",x,argv[x]);

    long a[] = {1,2,3,4,5,6,7,8,9, 0};
    long *p = a;

    printf("sizeof(a)=%ld\n",sizeof(a));
    printf("elements in a = %ld\n",sizeof(a)/sizeof(long));
    printf("sizeof(p)=%ld\n",sizeof(p));
    printf("sizeof(*p)=%ld\n",sizeof(*p));

    for(int x=0;x<(sizeof(a)/sizeof(long));x++)
        printf("\ta[%d]=%ld\n",x,a[x]);

    a[5] = 35;

    while(*p)
        printf("Element of a = %ld\n", *p++);

    MyStruct mstruct[] = {{1,'a',234},{2,'b',3434},{3,'c',5453}};
    MyStruct mstruct2[1024] = {{0,0,0}};

    printf("sizeof(mstruct)=%ld\n",sizeof(mstruct));
    printf("sizeof(mstruct2)=%ld\n",sizeof(mstruct2));


    }
