#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define BUF_SIZE 30
int main(int argc, char *argv[]){
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  int serv_sd, clnt_sd;
  FILE *fp;
  char buf[BUF_SIZE];
  int read_cnt;

  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t clnt_adr_sz;

  fp = fopen("file_serv.c", "rb");
  serv_sd = socket(PF_INET, SOCK_STREAM, 0);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
  listen(serv_sd, 5);

  clnt_adr_sz = sizeof(clnt_adr);
  clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

  while(1) {
    read_cnt = fread((void *)buf, 1, BUF_SIZE, fp);
    // if read data smaller than BUF_SIZE (if we reached to the end of file)
    if (read_cnt < BUF_SIZE) {
      // send the last content to the client
      write(clnt_sd, buf, read_cnt);
      break;
    }
    write(clnt_sd, buf, BUF_SIZE);
  }

  // close output stream
  shutdown(clnt_sd, SHUT_WR);
  // receive a respond from input stream
  read(clnt_sd, buf, BUF_SIZE);
  printf("Message from client: %s \n", buf);

  fclose(fp);
  close(clnt_sd);
  close(serv_sd);
  return 0;
}
