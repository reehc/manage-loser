#ifndef TODO_LIST_H_
#define TODO_LIST_H_

#include <stdbool.h>

typedef struct todo_node{
  char *todo;
  struct todo_node *next;
} todo_node;

typedef struct todo_queue{
  todo_node *head;
  todo_node *tail;
  int size;
} todo_queue;

todo_queue *q_new();
void        q_free(todo_queue *q);
bool        q_insert_head(todo_queue *q, char *todo);
bool        q_insert_tail(todo_queue *q, char *todo);
bool        q_remove_head(todo_queue *q);
void        q_reverse(todo_queue *q);

bool        q_conf(todo_queue *q, char *fn);
void        q_show(todo_queue *q);

#endif
