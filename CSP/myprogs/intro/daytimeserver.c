#include "unp.h"
#include "time.h"

int main(int argc, char **argv) {
	int 			listenfd, connfd; //socket ids, one: listening, second: connected
	struct sockaddr_in 	servaddr; //address struct
	char 			buff[MAXLINE]; //buffer to hold data
	time_t 			ticks; //for calculating date and time

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

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks)); //construct data to return
		Write(connfd, buff, strlen(buff)); //write data to client

		//Close(connfd);
	}
}
