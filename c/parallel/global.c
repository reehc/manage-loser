#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int flag = 1;

void *change(void *arg) {
  int *i = (int *)arg;
  while(1) { usleep(10000);*i=0;}
  //flag=0;
  pthread_exit(NULL);
}

int main(int argc, char argv[]) {
  int ret;
  pthread_t tid;

  ret = pthread_create(&tid, NULL, change, &flag);
  if (ret != 0) {
    printf("Can't create pthread (%s)\n", strerror(errno));
    exit(-1);
  }
  while (1) {
	if (flag) printf("Yes, I am ture!\n");
	else printf("0000000000\n");
  }
  pthread_join(tid, NULL);
  //while (flag++) printf("%d: Yes, I am ture!\n", flag);
  return 0;
}
