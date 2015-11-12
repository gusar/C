#include "unp.h"
#include <errno.h>

int readLine(int);

int main(int argc, char **argv)
{
	int sockfd = 0;
	struct sockaddr_in servaddr;\

	int GOOGLE_SMTP_PORT = 25;
	char GOOGLE_SMTP_ADDRESS[] = "64.233.166.26";
	char DIT_IP[] = "HELO 147.252.234.34\r\n";
	char mailfrom[MAXLINE];
	char mailto[MAXLINE];
	char subject[MAXLINE];
	char body[MAXLINE];
	char string[MAXLINE];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		err_sys("socket error");
	}

	/*
	* Set up socket connection
	*/
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(GOOGLE_SMTP_PORT);
	if (inet_pton(AF_INET, GOOGLE_SMTP_ADDRESS, &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", GOOGLE_SMTP_ADDRESS);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0 )
		err_sys("connect error");
	/**************************/

	/*
	* Construct and send SMTP commands
	*/
	// Initialise communication with HELO
	if (readLine(sockfd) > 0) {
		Write(sockfd, DIT_IP, strlen(DIT_IP));
	}

	// Sender email
	if (readLine(sockfd) > 0) {
		printf("\nMail from: ");
		if (scanf("%s", mailfrom) > 0) {
			strcpy(string, "MAIL FROM: <");
			strcat(strcat(string, mailfrom), ">\r\n");
			Write(sockfd, string, strlen(string));
		}
	}

	// Recepient email
	if (readLine(sockfd) > 0 ) {
		printf("\nMail to: ");
		if (scanf("%s", mailto) > 0) {
			strcpy(string, "RCPT TO: <");
			strcat(strcat(string, mailto), ">\r\n");
			Write(sockfd, string, strlen(string));
		}
	}

	// Announce data section
	if (readLine(sockfd) > 0)  {
		char data[] = "DATA\r\n";
		Write(sockfd, data, strlen(data));
	}

	// Data section
	if(readLine(sockfd) > 0) {
		char request[MAXLINE];

		strcpy(request, "From: ");
		strcat(strcat(request, mailfrom), "\r\n");
		Write(sockfd, request, strlen(request));

		strcpy(request, "To: ");
		strcat(strcat(request, mailto), "\r\n");
		Write(sockfd, request, strlen(request));

		printf("\nSubject: ");
		if (scanf("%s", subject) >= 0) {
			strcpy(request, "To: ");
			strcat(strcat(request, subject), "\r\n");
			Write(sockfd, request, strlen(request));
		}

		strcpy(request, "\r\n");
		Write(sockfd, request, strlen(request));

		printf("\nBody: ");
		if (scanf("%s", body) > 0) {
			strcpy(request, body);
			strcat(request, "\r\n");
			Write(sockfd, request, strlen(request));
		}

		strcpy(request, "\r\n");
		Write(sockfd, request, strlen(request));

		strcpy(request, ".\r\n");
		Write(sockfd, request, strlen(request));

		readLine(sockfd);
	}
	/*****************************************/

	exit(0);
}


int readLine(int sock) {
	printf("\r\n");
	char line[MAXLINE];
	int n = 0;
	int counter = 0;
	while((n = read(sock, line, MAXLINE)) > 0) {
		counter++;
		line[n] = 0; //null terminate
		if(fputs(line, stdout) == EOF) { //print data time and data returned from server
			err_sys("fputs error");
		}
		if(strstr(line, "\r\n\r\n") != NULL) {
			break;
		}
		break;
	}
	return n;
}
