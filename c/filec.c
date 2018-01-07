#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *fn = argv[1];
  if (argc == 1) {
    printf("args, please.");
    exit(-1);
  } else if (argc == 2) {
    FILE *fp = fopen(fn, "r");
    if (fp == NULL) {
      printf("%s: %s\n", fn, strerror(errno));
      exit(-2);
    }
    char c;
    do { c = fgetc(fp); printf("%c", c);  } while (c != EOF);
    fclose(fp);
  } else if (argc == 3) {
    FILE *fp = fopen(fn, "w");
    if (fp == NULL) exit(-3);
    char *string = argv[2];
    while (*string != '\0')
      fputc(*(string++), fp);
    fclose(fp);
  }
  return 0;
}
