#include "unp.h"
#include "time.h"

int main(int argc, char **argv) {
	int 			listenfd, connfd; //socket ids, one: listening, second: connected
	socklen_t	len;
	struct 		sockaddr_in 	servaddr, cliaddr;; //address struct
	char 			buff[MAXLINE]; //buffer to hold data
	time_t 		ticks; //for calculating date and time

	if (argc != 2) //verifies number of args
		err_quit("usage: <Program Name> <Port No.>");

	listenfd = Socket(AF_INET, SOCK_STREAM, 0); //create socket

	bzero(&servaddr, sizeof(servaddr)); //zero and fill in server addr struct
	servaddr.sin_family		= AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY); //connect to any local ip
	servaddr.sin_port		= htons(atoi(argv[1])); // daytime serv port number

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr)); //connects socket to external interface

	Listen(listenfd, LISTENQ); //changes socket to passive listenining

	for ( ; ; ) {
		len = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *) &cliaddr, &len); //accept next connection request from cli

		printf("\r\nclient addr %lu\r\n", &cliaddr.sin_addr);
		printf("client port %hu\r\n", &cliaddr.sin_port);

		printf("connection from %s, port %d\n",
				Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
				ntohs(cliaddr.sin_port));

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks)); //construct data to return
		Write(connfd, buff, strlen(buff)); //write data to client

		Close(connfd);
	}
}
