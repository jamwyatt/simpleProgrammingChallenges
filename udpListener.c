#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/wait.h>

#include <string.h>
#include <errno.h>

extern int errno;


#define PORT	10024


void error(const char *s) {
	fprintf(stderr,"%s: %s\n",s, strerror(errno));
	exit(-1);
	}


int startListener(int port) {

	struct sockaddr_in sa;
	int val;
	int sock;

	if((sock=socket(PF_INET,SOCK_DGRAM,0)) < 0)
		error("socket");

	if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0)
		error("setsockopt");

	sa.sin_family = PF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = htonl(INADDR_ANY); 

	if(bind(sock,(struct sockaddr*)&sa,sizeof(sa)) < 0)
		error("bind");

	return(sock);
	}

int listener(int sock) {

	size_t len;
	char buffer[10*1024];
	while(len=recv(sock,buffer,sizeof(buffer),0)) {
		buffer[len] = '\0';
		printf("Received [%s]\n",buffer);
		}

	error("recv failed");

	return(0);
	}


main(int argc, char *argv[]) {
	int listenSocket, port;
	if(argc == 2)
		port = atoi(argv[1]);
	else
		port = PORT;
	listenSocket=startListener(port);
	exit(listener(listenSocket));
	}
