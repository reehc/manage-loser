#include <stdio.h>

int main(int argc, char *argv[]) {
  int *p = (int *)0x77FF;
  while (*p == 0) printf("flag == 0");
  return 0;
}
