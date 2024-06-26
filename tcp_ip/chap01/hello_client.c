#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

// 172.16.31.91
int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in serv_addr;
  char message[30];
  int str_len;

  if (argc != 3) {
    printf("Usage : %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1)
    error_handling("socket() error");

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  // inet_addr: convert a string to inet_addr => arpa/inet.h
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  // port has to be network short
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    error_handling("connect() error");

  // you have to give last index of socket (not length)
  str_len = read(sock, message, sizeof(message) - 1);
  if (str_len == -1)
    error_handling("read() error");

  printf("Message from server : %s \n", message);
  close(sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
