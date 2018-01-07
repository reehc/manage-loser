#include <stdio.h>
#include <stdlib.h>

/*
 * WARNING!
 * const means "read-only" in c!
 * so it's still a run-time variable!
 * use enum to make REAL CONSTANT.
 */

//const MAX_LINE = 70;
//int obj_num = 3;

enum {
  MAX_LINE = 70,
  OBJ_NUM = 3
};

typedef struct {
  int id;
  float x_coord;
  float y_coord;
  char name[MAX_LINE + 1];
} cheer_point;

cheer_point objs[OBJ_NUM] = {
  {0, 1.5, 8.4, "First-object"},
  {1, 9.2, 7.4, "Second-object"},
  {2, 4.1, 5.6, "Final-object"}
};

int main(int argc, char *argv) {
  FILE *out = fopen("data", "a");
  if (out == NULL) exit(-1);

  for (int i = 0; i < OBJ_NUM; ++i) {
    fprintf(out, "%d %f %f %s\n",
	    objs[i].id,
	    objs[i].x_coord,
	    objs[i].y_coord,
	    objs[i].name);
    // Alternatively, use
    /*
    snprintf(line, 80, "%d %f %f %s\n", 
             ...);
    fputs(line, out);
    
    PROTOTYPES:
    int fprintf(FILE *stream, FORMAT);
    int sprintf(char *str, FORMAT);

    // Conversely, use fscanf() to read formatted data from a file~~~
    // Alternatively, use
    fgets(in, 80, line);
    sscanf(line, 80, FORMAT);

    PROTOTYPES:
    int fscanf(FILE *stream, FORMAT);
    int sscanf(const char *str, FORMAT)
     */
  }

  fclose(out);
}

