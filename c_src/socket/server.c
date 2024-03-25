#include <arpa/inet.h>
#include <assert.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // for system call

#define MAX_USER 100

pthread_mutex_t mutex;

int dataSockets[MAX_USER];
int numberOfClients = 0;

void *client_proc(void *arg) {
  int dataSocket = *(int *)arg;

  for (;;) {
    char buf[1024];
    // blocking unless it receive
    // maximum readable size is 1024
    int nread = read(dataSocket, buf, 1024);
    if (nread == 0) {
      // end of file if client is closed `close(dataSocket)`
      break;
    } else if (nread == -1) {
      // error is occured!!
    } else {
      // buf msg -> all clients!!
      pthread_mutex_lock(&mutex);
      for (int i = 0; i < numberOfClients; ++i) {
        // a number of reads
        // TODO: Lock
        write(dataSockets[i], buf, nread);
      }
      pthread_mutex_unlock(&mutex);
    }
  }

  pthread_mutex_lock(&mutex);
  for (int i = 0; i < numberOfClients; ++i) {
    if (dataSocket == dataSockets[i]) {
      for (int j = i; j < numberOfClients - 1; ++j) {
        // TODO: Lock
        dataSockets[j] = dataSockets[j + 1];
      }
      break;
    }
  }
  --numberOfClients;
  pthread_mutex_unlock(&mutex);
  close(dataSocket);
  return NULL;
}

int main(void) {
  pthread_mutex_init(&mutex, NULL);
  // file descripter
  // ipv4 => AF_INET
  // TCP  => SOCK_STREAM
  // select protocol automatically => 0
  int servSocket = socket(AF_INET, SOCK_STREAM, 0);
  // if (servSocket == -1) {
  //   fprintf(stderr, "can't make a socket");
  //   // 0 : success
  //   exit(1);
  // }
  assert(servSocket != -1); // run when it's true

  // assign a name to a socket
  struct sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  // network => big endian (12 <- 12345678)
  // host to network long
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  // 0 ~ 1024 : reserved port
  // host to network short
  my_addr.sin_port = htons(7777); // TODO : explane

  // pointer rule 3 : when convert struct to reduce
  assert(bind(servSocket, (struct sockaddr *)&my_addr,
              sizeof(my_addr)) == 0); // size can differ in address

  // 5 connection will accept
  assert(listen(servSocket, 5) == 0);

  for (;;) {
    struct sockaddr_in clientAddr;
    socklen_t addrLen;

    int dataSocket =
        accept(servSocket, (struct sockaddr *)&clientAddr, &addrLen);
    assert(dataSocket != -1);

    // TODO: Lock
    pthread_mutex_lock(&mutex);
    dataSockets[numberOfClients++] = dataSocket;
    pthread_mutex_unlock(&mutex);

    // print client info
    printf("client ip : %s", inet_ntoa(clientAddr.sin_addr));
    // make a clone! -> read / write
    pthread_t PId;
    pthread_create(&PId, NULL, client_proc, &dataSocket);
  }

  // close(dataSocket);
  close(servSocket);
  pthread_mutex_destroy(&mutex);
  return 0;
}
