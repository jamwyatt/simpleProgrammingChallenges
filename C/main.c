#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Assume simple alphabet of A-Za-z0-9
const char * stringCompress(char *str, char *output, int max) {

    if(str == NULL || *str == '\0')
        return(str);

    int index = 0;

    // Need to detect when run out of space in output!

    char newChar = 0;
    int count = 0;
    for(char *i = str; *i != '\0'; i++) {
        if(newChar != *i) {
            if(count > 0)
                index += snprintf(&output[index],max-index,"%c%d",newChar,count);
            newChar = *i;
            count = 1;
            }
        else
            count++;
        }

    if(count > 0)
        index += snprintf(&output[index],max-index,"%c%d",newChar,count);

    return(output);
    }


int main(int argc, char *argv[]) {

    for(int i=0;i<argc;i++)
        printf("Arg %d: %s\n",i,argv[i]);

    if(argc != 2) {
        fprintf(stderr, "Not enough arguments ... need one\n\n");
        exit(-1);
        }

    // Bad memory management ... either restrict input or go dynamic

    char compressed[1024];
    memset(&compressed,0,sizeof(compressed));
    printf("Compressed %s -> %s\n", argv[1], stringCompress(argv[1], compressed, 1024));
    if(strlen(compressed) > strlen(argv[1]))
        printf("Compression not useful\n");

    exit(0);
    }
