#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 30

void error_handling(char *msg);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  int sock;
  char message[BUF_SIZE];
  struct sockaddr_in my_adr, your_adr;
  socklen_t adr_sz;
  int str_len, i;

  sock = socket(PF_INET, SOCK_DGRAM, 0);
  if (sock == -1)
    error_handling("socket() error");

  memset(&my_adr, 0, sizeof(my_adr));
  my_adr.sin_family = AF_INET;
  my_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  my_adr.sin_port = htons(atoi(argv[1]));

  if (bind(sock, (struct sockaddr *)&my_adr, sizeof(my_adr)))
    error_handling("bind() error");

  for (i = 0; i < 3; ++i) {
    sleep(5);                  // delay 5s
    adr_sz = sizeof(your_adr); // calculate a correspond size
    // read by BUF_SIZE
    // NOTE: UDP recieve data in specific boundary, not a stream.
    str_len = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr *)&your_adr,
                       &adr_sz);
    printf("Message %d: %s \n", i + 1, message);
  }
  close(sock);
  return 0;
}

void error_handling(char *msg) {
  fputs(msg, stderr);
  fputc('\n', stderr);
  exit(1);
}
