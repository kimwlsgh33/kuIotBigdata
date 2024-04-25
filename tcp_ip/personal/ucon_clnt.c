#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 30
void error_handling(char *msg);
int main(int argc, char *argv[]){
  if (argc != 3) {
    printf("Usage: %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  int sock;
  char message[BUF_SIZE];
  int str_len;
  socklen_t adr_sz; // this is unnecessary

  struct sockaddr_in serv_adr, from_adr; // from_adr is unnecessary
  
  sock = socket(PF_INET, SOCK_DGRAM, 0);
  if (sock == -1)
    error_handling("socket() error");

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_adr.sin_port = htons(atoi(argv[2]));

  // connect destination IP & port to udp socket
  if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
    error_handling("connect() error");

  while(1) {
    fputs("Insert message(q to quit): ", stdout);
    fgets(message, sizeof(message), stdin);
    if(!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
      break;

    // sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    // this can be work because the socket is connected!
    write(sock, message, strlen(message));

    // adr_sz = sizeof(from_adr);
    // str_len = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_adr, &adr_sz);

    str_len = read(sock, message, sizeof(message) - 1);
    message[str_len] = 0;
    printf("Message from server: %s", message);
  }
  
  close(sock);
  return 0;
}

void error_handling(char *msg){
  fputs(msg, stderr);
  fputc('\n', stderr);
  exit(1);
}
