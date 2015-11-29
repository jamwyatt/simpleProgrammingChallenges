#include <stdio.h>
#include <string.h>


void permuteString(char *prefix, char *str) {

	if(strlen(str) == 2) {
		printf("%s%c%c\n",prefix,*str, *(str+1));
		printf("%s%c%c\n",prefix,*(str+1), *str);
		return;
		}
	char *p = str;
	for(p=str;*p;p++) {
		char newPrefix[1024];
		char newStr[1024];
		int x=0;

		snprintf(newPrefix,sizeof(newPrefix),"%s%c",prefix,*p);
		char *i;
		for(i=str;*i;i++) {	// build newStr to represent all characters excpet *p
			if(i != p)
				newStr[x++] = *i;
			}
		newStr[x] = '\0';
		permuteString(newPrefix,newStr);
		}

	}

int main(int argc, char *argv[]) {
	if(argc > 1)
		permuteString("",argv[1]);
	return(0);
	}

