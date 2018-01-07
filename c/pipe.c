/*
Pipe, or half-duplex pipe is used for IPC(inter-process commication), and a full-duplex communication requires the Socket API, which is in next chapter~~

A PIPE IS NOTHING MORE THAN A PAIR OF FILE DESCRIPTORS...
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

enum {
  MAX_LINE = 256,
  PIPE_STDIN = 0,
  PIPE_STDOUT= 1
};

int main(int argc, char *argv[]){
  const char *string = "I mean nothing.";
  int ret, my_pipe[2];
  char buffer[MAX_LINE];

  /* Create the pipe */
  ret = pipe(my_pipe);

  if (ret == 0) {
    if (fork() == 0) {
      // Child process returns 0.
      ret = read(my_pipe[PIPE_STDIN], buffer, MAX_LINE);
      buffer[ret] = '\0';
      printf("Child01 reads: %s\n", buffer);
    } else {
      ret = write(my_pipe[PIPE_STDOUT], string, strlen(string));
      ret = wait(NULL);
    }
  } 
  return 0;
}
