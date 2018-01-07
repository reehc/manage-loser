#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "todo_queue.h"

int main(int argc, char *argv[]) {
  char *configure = "./configure";
  todo_queue *q = NULL;
  q = q_new();
  if(!q_conf(q, configure)){
    printf("Configuration failed.\n");
    exit(-5);
  }
  if (argc == 2) {
    if (strcmp(argv[1], "done") == 0) {
      if (q->head != NULL)
        printf("Done! ==> %s", q->head->todo);
      q_remove_head(q);
      system("sed '1d' configure > gg; mv gg configure");
    }
  }
  q_show(q);
  q_free(q);
  return 0; 
}
