#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp = fopen("data", "r");
  if (fp == NULL) exit(-1);

  char bytes[70];
  // shift 0 byte from the start
  fseek(fp, 0, SEEK_SET);
  // read 1 time 70 bytes
  fread(bytes, 70, 1, fp);
  bytes[69] = '\0';
  printf("bytes:\n%s\n", bytes);

  // Let's rewind!
  // same as fseek(fp, 0, SEEK_SET)!
  rewind(fp);
 
  fclose(fp);


  // Emmm, codes above don't really show binary data...Let's do it again!
  fp = fopen("./data", "a");
  // I got 0! I got ZERO!!!!!!
  printf("ftell after open: %d\n", ftell(fp));
  // easy to figure out args' meaning from above!
  fwrite((void *)bytes, 69, 1, fp);
  // Oh, I am doomed!
  // I am still writing ASCII...
  // But I am rewind~~~
  // rewind(fp);
  // Nonono, I need fseek!

  // Can't I fseek ???
  // fseek(fp, -69, SEEK_CUR);

  fpos_t file_pos;
  fgetpos(fp, &file_pos);
  rewind(fp);
  fsetpos(fp, &file_pos);
  // REALLY, append-open give U ZERO pos.
  printf("fgetpos: %d\n", file_pos);
  int i = 0xffffffff; // -1
  fwrite((void *)&i, 4, 1, fp);
  fclose(fp);

  // Emmm.. Not interesting...
  return 0;
}
