### 13 October 2015

Daytime Client | Daytime Server
---------------| --------------
Socket | Socket
| Bind (IN_ADDR_ANY)(PORT#)
connect | Listen
 write (GET) | Accept
read | Write
exit(0) [~Close(Sockfd)] | Close

```
snprintf(buff,
  sizeof(buff),
  "GET /index.html HTTP/1.1\r\nHost: www.comp.dit.ie\r\nConnection: close\r\n\r\n");

Write();
```
####HTTP basic operations:####
* GET
* POST
* HEAD
* PUT

```
GET /index HTTP/1.1 (initial line) (CRLF)
Program: Mozilla(1.1) header 1 (CRLF)
Date: ... header 2 (CRLF)
BLANK LINE (CRLF)
Message Body
```

### 3 November 2015 ###
```
void *the_data
int i;
char c;
the_data = &i;
the_data = &c;
printf("%d", *(int*)the_data);
orintf("%c", c);
*(char*)the_data;
```
##### Port ranges #####
* 0 - 1023 : Restricted
* 1024 - 65000 : Unrestricted
* 1024 - 5000 : Ephemeral

```
for ( ; ; ) {
  len = sizeof(cliaddr);
  connfd = Accept(listenfd, (SA *) &cliaddr, &len);
  printf("connection from %s, port %d\n",
      Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
      ntohs(cliaddr.sin_port));
}
```
