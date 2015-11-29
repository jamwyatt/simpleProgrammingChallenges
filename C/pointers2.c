#include <stdio.h>


int main(int argc, char *argv[]) {

    char *foo = "one two three";

    printf("sizeof(foo)=%lu\n",sizeof(foo));

    printf("address(foo)=%lu\n",(unsigned long)foo);
    printf("address(&foo)=%lu\n",(unsigned long)&foo);

    char bar[] = {"xyz"};
    printf("\nsizeof(bar)=%lu\n",sizeof(bar));
    printf("address(bar)=%lu\n",(unsigned long)bar);
    printf("address(&bar[0])=%lu\n",(unsigned long)&bar[0]);
    printf("address(&bar)=%lu\n",(unsigned long)&bar);

    char bart[] = "abc";
    printf("\nsizeof(bart)=%lu\n",sizeof(bart));
    printf("address(bart)=%lu\n",(unsigned long)bart);
    printf("address(&bart[0])=%lu\n",(unsigned long)&bart[0]);
    printf("address(&bart)=%lu\n",(unsigned long)&bart);

    char *p = bart;
    while(*p)
        printf("Element of bart = %c\n", *p++);

    }
