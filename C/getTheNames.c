#include <stdio.h>
#include <string.h>

char * target = "one  'Robert' 'three' xxx  'Wyatt  ";



int main(int argc, char * argv[]) {

    char *names[5] = {};
    char **name = names;
    char buffer[15] = {};
    char * buf = buffer;
    printf("Buffer=%s\n",buffer);

    int inWord = 0;
    while(*target && (buf < &buffer[sizeof(buffer)-1])) {
        if(inWord) {
            if(*target == '\'') {
                // The ending quote
                inWord = 0;
                *buf++ = '\0';
                }
            else
                *buf++ = *target;    // Just copy
            }
        else {
            // Looking for a starting '
            if(*target == '\'') {
                inWord = 1;
                *name++ = buf;
                }
            }
        target++;
        }

    printf("Last Buffer Element[%lu]=[%c] (just before the NUL)\n",sizeof(buffer)-2,buffer[sizeof(buffer)-2]);

    char **i = names;
    while(*i)
        printf("Name: [%s]\n", *i++);
    
    }
