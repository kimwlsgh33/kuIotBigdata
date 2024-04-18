#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
  int serv_sock;
  int clnt_sock;

  // sockaddr_in, socklen_t => arpa/inet.h
  struct sockaddr_in serv_addr;
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_size;

  char message[] = "Hello World!";

  if (argc != 2) {
    printf("Usage : %s <port>\n", argv[0]);
    exit(1); //=> stdlib.h
  }

  // sys/socket.h
  // return => file descripter (indexs of opend file)
  // PF_INET: Protocol Family Internet
  // SOCK_STREAM: TCP
  // 0: select protocol automatically
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (serv_sock == -1)
    error_handling("socket() error");

  // string.h
  // &serv_addr: A address to initialize
  // 0: start index
  // sizeof(serv_addr): size of buffer
  memset(&serv_addr, 0, sizeof(serv_addr));
  // AF_INET: Address Family Internet
  serv_addr.sin_family = AF_INET;
  // htonl: host to network long
  // INADDR_ANY: Allowing any kinds of array => netinet/in.h
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  // htons: host to network short
  // atoi: ascii to integer
  // argv[1]: default port
  serv_addr.sin_port = htons(atoi(argv[1]));

  // bind the file descripter to the socket
  if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    error_handling("bind() error");

  // convert the socket to listen
  if (listen(serv_sock, 5) == -1)
    error_handling("listen() error");

  clnt_addr_size = sizeof(clnt_addr);
  // HACK: blocking!
  clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
  if (clnt_sock == -1)
    error_handling("accept() error");

  // unistd.h
  // you have to give length of socket (not last index)
  write(clnt_sock, message, sizeof(message));
  close(clnt_sock);
  close(serv_sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
