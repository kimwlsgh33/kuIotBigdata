#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error_handling(char *message);

int main(void) {
  int fd;
  char buf[] = "Let's go!\n";
  // fcntl: file control
  // O_: open
  // O_CREAT: create if not exist
  // O_WRONLY: write only
  // O_TRUNC: truncate
  fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);

  if (fd == -1)
    error_handling("open() error!");
  printf("file descripter: %d \n", fd);

  if(write(fd, buf, sizeof(buf)) == -1) 
    error_handling("write() error!");
  
  close(fd);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
