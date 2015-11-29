#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Assume simple alphabet of A-Za-z0-9
int isPermutation(char *a, char *b) {

    if(a == NULL || b == NULL)
        return(-1);

    char testZone[256];
    memset(testZone,0,sizeof(testZone));

    int aSize = 0;
    for(char *i=a;*i != '\0';i++) {
        aSize++;
        testZone[*i]++;
        }

    int bSize = 0;
    for(char *i=b;*i != '\0';i++) {
        bSize++;
        testZone[*i]--;
        }

    for(int i=0;i<sizeof(testZone);i++)
        if(testZone[i] != 0)
            return(-1);

    return(0);       // Good return
    }


int main(int argc, char *argv[]) {

    for(int i=0;i<argc;i++)
        printf("Arg %d: %s\n",i,argv[i]);

    if(argc != 3) {
        fprintf(stderr, "Not enough arguments ... need two\n\n");
        exit(-1);
        }

    if(isPermutation(argv[1], argv[2]) == 0)
        printf("They are an anagram of each other\n\n");
    else
        printf("No so much\n\n");

    exit(0);
    }
