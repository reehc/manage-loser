#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_QUEUE 10

int arr[10] = {0};
volatile int head = 0, tail = 0;

void *producer(void *args);
void *consumer(void *args);

int main(int argc, char *argv[]) {
  int gap1, gap2;
  if (argc == 3) {
    gap1 = atoi(argv[1]);
    gap2 = atoi(argv[2]);
    printf("%d <-> %d\n", gap1, gap2);
  }
  pthread_t p, c;
  pthread_create(&p, NULL, producer, (void *)&gap1);
  pthread_create(&c, NULL, consumer, (void *)&gap2);

  pthread_join(p, NULL);
  pthread_join(c, NULL);

  return 0;
}

void *producer(void *args) {
  int gap = 1;
  if (args != NULL) gap = *(int *)args;
  // Produce
  int init = 0;
  while (1) {
    arr[tail++] = (init++);
    tail %= MAX_QUEUE;
    init %= 7777;
    sleep(gap);
  }
}

void *consumer(void *args) {
  int gap = 2;
  if (args != NULL) gap = *(int *)args;
  // Consume
  while (1) {
    while(head != tail) {head++; head%=MAX_QUEUE;}
    printf("get: %d\n", arr[head]);
    sleep(gap);
  }
}
