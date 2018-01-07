#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 256
 
int main(int argc, char *argv[]) {
  int serverFd, connectionFd;
  struct sockaddr_in servaddr;
  char timebuffer[MAX_BUFFER+1];
  time_t currentTime;

  // Create a socket
  // AF_INET(IPv4) domain, reliable stream protocol type
  // 0 specifies to use the default protocol: TCP
  serverFd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr)); // Initialize to zero
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(7777);
  // htonl: host-to-network-long

  bind(serverFd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(serverFd, 5);

  while (1) {
    connectionFd = accept(serverFd, (struct sockaddr *)NULL, NULL);
    if (connectionFd >= 0) {
      currentTime = time(NULL);
      snprintf(timebuffer, MAX_BUFFER, "%s\n", ctime(&currentTime));
      write(connectionFd, timebuffer, strlen(timebuffer));
      close(connectionFd);
    }
  }
}
