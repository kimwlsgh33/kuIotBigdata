#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 30

int main(int argc, char *argv[]){
  if (argc != 3) {
    printf("Usage: %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  // socket descripter
  int sd;
  // file to store data
  FILE *fp;
  // buffer to read data from the socket
  char buf[BUF_SIZE];
  // number to recognize the EOF
  int read_cnt;
  // socket addr
  struct sockaddr_in serv_adr, clnt_adr;

  fp = fopen("receieve.dat", "wb");
  sd = socket(PF_INET, SOCK_STREAM, 0);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_adr.sin_port = htons(atoi(argv[2]));

  connect(sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

  while((read_cnt = read(sd, buf, BUF_SIZE)) != 0)
    fwrite((void *)buf, 1, read_cnt, fp);

  puts("Received file data");
  write(sd, "Thank You", 10);
  fclose(fp);
  close(sd);
  return 0;
}
