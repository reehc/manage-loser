#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *in, *out;
  // open stdout & stdin
  // ??????
  out = fopen(1, "w");
  in = fdopen(0, "r");

  if (out == NULL || in == NULL) exit(-1);

  const int LEN = 7;
  char buffer[LEN];
  while ((fgets(buffer, LEN, in)) != NULL)
    fputs(buffer, out);

  fclose(out);
  fclose(in);

  return 0;
}
