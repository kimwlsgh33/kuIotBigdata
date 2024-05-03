#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_handling(char *msg);

int main(int argc, char *argv[]){
  int tcp_sock, udp_sock;
  int sock_type;
  socklen_t option;
  int state;

  return 0;
}

void error_handling(char *msg) {
  fputs(msg, stderr);
  fputc('\n', stderr);
  exit(1);
}
