#include <stdio.h>

typedef struct _mystruct {
        long foo;
        short bar;
        char abc;
        struct _mystruct *next;
        } MyStruct;

int main(int argc, char *argv[]) {

    MyStruct ms[10] = {};

    printf("sizeof(MyStruct)=%lu\n",sizeof(MyStruct));
    for(int x = 0; x < (sizeof(ms)/sizeof(MyStruct));x++)
        printf("address(ms[%d])=%lu\n",x,(unsigned long)&ms[x]);
    printf("\n");

    MyStruct *p = &ms[0];
    printf("pointer(p)=%lu\n",(unsigned long)p);
    printf("pointer(++p)=%lu\n",(unsigned long)++p);
    printf("pointer(++p)=%lu\n",(unsigned long)++p);
    printf("pointer(p+1)=%lu\n",(unsigned long)(p+1));
    printf("\n");

    MyStruct *p0 = &ms[0];
    MyStruct *p1 = &ms[1];
    printf("p1-p0=%lu\n",p1-p0);
    printf("(unsigned casted) p1-p0=%lu\n",(unsigned long)p1-(unsigned long)p0);
    }
