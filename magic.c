#include <stdio.h>
#include <string.h>

int checkMagicNumber(char *buffer, int size) {
	char substr[1024];
	int x;
	if(size>=strlen(buffer))
		return(1);
	strncpy(substr,buffer,size);
	sscanf(substr,"%d",&x);
	if(x % size == 0) {
		return(checkMagicNumber(buffer,size+1));
		}
	return(0);
	}


int main() {
	char buffer[1024];

	while(fgets(buffer,sizeof(buffer),stdin)) {
		if(checkMagicNumber(buffer,2)) {
			printf("Found %s\n",buffer);
			return(0);
			}
		}
	return(1);
	}
