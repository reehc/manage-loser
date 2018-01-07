#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 128

int main(int argc, char *argv[]) {
  int connectionFd, in, index = 0, limit = MAX_BUFFER;
  struct sockaddr_in servaddr;
  char timebuffer[MAX_BUFFER+1];

  connectionFd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(7777);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(connectionFd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  while ((in = read(connectionFd, &timebuffer[index], limit)) > 0) {
    index += in;
    limit -= in;
  }

  timebuffer[index] = 0;
  printf("\n%s\n", timebuffer);

  close(connectionFd);

  return 0;
}
