#include <arpa/inet.h>
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void *send_msg(void *arg) {
  int dataSocket = *(int *)arg;
  for (;;) {
    char buf[1024];
    // read until `\n` -> \n\0
    fgets(buf, 1024, stdin);

    if (strcmp(buf, "/quit\n") == 0) {
      break;
    }

    write(dataSocket, buf, strlen(buf));
  }

  close(dataSocket);
  return NULL;
}

void *recv_msg(void *arg) {
  int dataSocket = *(int *)arg;
  for (;;) {
    char buf[1024];
    int nread = read(dataSocket, buf, 1024);

    if (nread == 0) { // EOF. close(dataSocket)
      break;
    } else if (nread == 1) {
      break;
    } else {
      buf[nread] = '\0';
      printf("%s\n", buf);
    }
  }

  return NULL;
}

int main(void) {
  int dataSocket = socket(AF_INET, SOCK_STREAM, 0);
  assert(dataSocket != -1); // if not error
  struct sockaddr_in servAddr;
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr =
      inet_addr("127.0.0.1"); // loop back - host computer itself
  servAddr.sin_port = htons(7777);
  assert(connect(dataSocket, (struct sockaddr *)&servAddr, sizeof(servAddr)) ==
         0);

  // create threads - input client msg / print server msg
  pthread_t pId1, pId2;
  pthread_create(&pId1, NULL, send_msg, &dataSocket);
  pthread_create(&pId2, NULL, recv_msg, &dataSocket);

  // blocking main thread
  // for (;;) {
  // }
  // close(dataSocket);
  pthread_join(pId1, NULL);
  pthread_join(pId2, NULL);
  return 0;
}
