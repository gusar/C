/**
* CSP Lab Test
* Andrejs Lahs
* C13766231
* 01/12/2015
*/

#include "unp.h"
#include "time.h"
#include "string.h"

int main(int argc, char **argv) {
	int listenfd, connfd; //socket ids, one: listening, second: connected
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr; //address struct
	char buff[MAXLINE], recvline[MAXLINE]; //buffer to hold data
  char logintag[8], passtag[7], login[MAXLINE], pass[MAXLINE];
  char expectedLogin[7] = "admin";
  char expectedPass[6] = "pass";

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
    len = sizeof(cliaddr);
    // Accept connection
		connfd = Accept(listenfd, (SA *) &cliaddr, &len); //accept next connection request from cli

    // Print address and port
    printf("connection from %s, port %d\n",
		Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
		ntohs(cliaddr.sin_port));

    // If request empty, quit with error
    if (read(connfd, recvline, MAXLINE) < 1)
    err_sys("fputs error");

    // Print request
    fputs(recvline, stdout);

    // Assign user request values
    sscanf(recvline, "%s %s %s %s", logintag, login, passtag, pass);

    // Compare user values to expected values and send appropriate response
    if (strcmp(login, expectedLogin) == 0 && strcmp(pass, expectedPass) == 0) {
      snprintf(buff, sizeof(buff), "SUCCESS\r\n\r\n"); //construct data to return
    	Write(connfd, buff, strlen(buff)); //write data to client
      printf("Correct credentials\n");
    } else {
      snprintf(buff, sizeof(buff), "DENIED\r\n\r\n"); //construct data to return
    	Write(connfd, buff, strlen(buff)); //write data to client
      printf("Incorrect credentials\n");
    }

    // Close conneciton
		Close(connfd);
	}
}
