#include "unp.h"
#include "time.h"
#include "string.h"

int main(int argc, char **argv) {
	int 		listenfd, connfd, n; //socket ids, one: listening, second: connected
	socket_t 	len;
	struct 		sockaddr_in servaddr, cliaddr; //address struct
	char 		buff[MAXLINE], recvline[MAXLINE]; //buffer to hold data

	if (argc != 2) //verifies number of args
		err_quit("usage: <Program Name> <Prot No.>");

	listenfd = Socket(AF_INET, SOCK_STREAM, 0); //create socket

	bzero(&servaddr, sizeof(servaddr)); //zero and fill in server addr struct
	servaddr.sin_family		= AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY); //connect to any local ip
	servaddr.sin_port		= htons(atoi(argv[1])); // daytime serv port number

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr)); //connects socket to external interface

	Listen(listenfd, LISTENQ); //changes socket to passive listenining

	for ( ; ; ) {
		connfd = Accept(listenfd, (SA *) NULL, NULL); //accept next connection request from cli

		while ( (n = read(connfd, recvline, MAXLINE)) > 0) {
			recvline[n] = 0; //null terminate
			if (fputs(recvline, stdout) == EOF) //print time and date returned from server
				err_sys("fputs error");

			if(strstr(recvline, "\r\n\r\n") != NULL) {
				printf("Double line break found!\n");
				break;
			}
		}

		snprintf(buff, sizeof(buff), "Boobies\r\n\r\n"); //construct data to return
		Write(connfd, buff, strlen(buff)); //write data to client

		Close(connfd);
	}
}
