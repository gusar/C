#include "unp.h"
#include <errno.h>
#include <string.h>

int readLine(int);
char* commandBuilder(int, char*, char*, char*, char*);

char input[MAXLINE];
int sockfd;

int main(int argc, char **argv) {
  sockfd = 0;
  struct sockaddr_in servaddr;

  int GOOGLE_SMTP_PORT = 25;
  char GOOGLE_SMTP_ADDRESS[] = "64.233.166.26";
  char mailfrom[MAXLINE];
  char mailto[MAXLINE];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    err_sys("socket error");
  }

  /*
  * Set up socket connection
  */
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(GOOGLE_SMTP_PORT);
  if (inet_pton(AF_INET, GOOGLE_SMTP_ADDRESS, &servaddr.sin_addr) <= 0) {
    err_quit("inet_pton error for %s", GOOGLE_SMTP_ADDRESS);
  }

  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0 ) {
    err_sys("connect error");
  }
  /**************************/

  /*
  * Construct and send SMTP commands
  * (refer to commandBuilder method)
  */

  // Initialise communication
  commandBuilder(1, "", "", "\0", "HELO 147.252.234.34\r\n");
  // Sender email
  strcpy(mailfrom, commandBuilder(1, "\nMail from: ", "MAIL FROM: <", "\0", ">\r\n"));
  // Recepient email
  strcpy(mailto, commandBuilder(1, "\nMail to: ", "RCPT TO: <", "\0", ">\r\n"));
  // Announce data section
  commandBuilder(1, "", "", "\0", "DATA\r\n");
  // Data section
  commandBuilder(1, "", "From: ", mailfrom, "\r\n");
  commandBuilder(0, "", "To: ", mailto, "\r\n");
  commandBuilder(0, "\nSubject: ", "Subject: ", "\0", "\r\n");
  commandBuilder(0, "", "", "\0", "\r\n");
  commandBuilder(0, "\nBody: ", "", "\0", "\r\n");
  commandBuilder(0, "", "", "\0", "\r\n");
  commandBuilder(0, "", "", "\0", ".\r\n");

  readLine(sockfd);
  printf("\nIf OK: Email sent succesfull.\n\n");
  /********************************************/

  exit(0);
}


/*
* Arguments
*   int reply: 1 if server reply is expected, otherwise 0.
*   char *message: display input field description.
*   char *prefix: first part of command.
*   char *in: predefined field input.
*   char *postfix: ending of command.
* Return
*   char*: input string for optional storage.
*/
char* commandBuilder(int reply, char *message, char *prefix, char *in, char *postfix) {
  char command[MAXLINE];
  if (reply == 1) {
    if (readLine(sockfd) <= 0) {
      return "No Server Response!\n";
    }
  }
  strcpy(input, in);
  strcpy(command, "\0");
  if (strlen(message) > 0) {
    printf("%s", message);
    while (scanf("%s", input) <= 0) {
      printf("Bad input. Enter again. %s", message);
    }
  }
  if (strlen(prefix) > 0) {
    strcat(command, prefix);
  }
  if (strlen(input) > 0) {
    strcat(command, input);
  }
  if (strlen(postfix) > 0) {
    strcat(command, postfix);
  }
  Write(sockfd, command, strlen(command));
  return input;
}


/*
* Read in server response
*/
int readLine(int sock) {
  char line[MAXLINE];
  int n = 0;
  int counter = 0;
  while((n = read(sock, line, MAXLINE)) > 0) {
    counter++;
    line[n] = 0; //null terminate
    if(fputs(line, stdout) == EOF) {
      err_sys("fputs error");
    }
    if(strstr(line, "\r\n\r\n") != NULL) {
      break;
    }
    break;
  }
  return n;
}
