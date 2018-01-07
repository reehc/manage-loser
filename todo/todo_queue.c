#include "todo_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

todo_queue *q_new() {
  todo_queue *q = malloc(sizeof(todo_queue));
  if (!q) return NULL;
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

void        q_free(todo_queue *q) {
  if (q == NULL) return;
  else {
    todo_node *node;
    while (q->head != NULL) {
      node = q->head;
      q->head = q->head->next;
      free(node);
    }
  }
  free(q);
}

bool        q_insert_head(todo_queue *q, char *todo) {
  if (q == NULL) return false;
  todo_node *node = malloc(sizeof(todo_node));
  if (node == NULL) return false;
  if (q->size > 0) {
    node->todo = todo;
    node->next = q->head;
    q->head = node;
  } else if (q->size == 0) {
    node->todo = todo;
    node->next = NULL;
    q->head = node;
    q->tail = node;
  } else {
    printf("What this operation is ?\n");
    exit(-1);
  }
  q->size++;
  return true;
}

bool        q_insert_tail(todo_queue *q, char *todo) {
  todo_node *newh;
  /* What should you do if the q is NULL? */
  if (q == NULL) return false;
  newh = malloc(sizeof(todo_node));
  /* What if malloc returned NULL? */
  if (newh == NULL) return false;
  if (q->size > 0) {
    newh->todo = todo;
    newh->next = NULL;
    q->tail->next = newh;
    q->tail = newh;
  } else if (q->size == 0)
    {
      newh->todo = todo;
      newh->next = NULL;
      q->head = newh;
      q->tail = newh;
    } else {
    printf("What this operation is ?\n");
    exit(-1);
  }
  q->size++;
  return true;
}

bool        q_remove_head(todo_queue *q) {
  if (q == NULL || q->head == NULL) return false;
  if (q->size > 1)
    {
      todo_node *temp = q->head;
      q->head = q->head->next;
      free(temp);
      q->size--;
    } else if (q->size == 1) {
    todo_node *temp = q->head;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    free(temp);
  } else {
    printf("What this operation is ?\n");
    exit(-2);
  }
  return true;
}

bool        q_conf(todo_queue *q, char *fn) {
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) exit(-2);
  char *line = NULL;
  size_t len;
  ssize_t read;
  while ((read = getline(&line, &len, fp)) != -1) {
    char *todo = malloc(len * sizeof(char));
    strcpy(todo, line);
    q_insert_tail(q, todo);
  }
  return true;
}

void        q_show(todo_queue *q) {
  if (q == NULL || q->head == NULL) {
    printf("Empty TODO\n");
    exit(-3);
  }
  todo_node *todo = q->head;
  int index = 1;
  while(todo) {
    printf("%d: %s", index++, todo->todo);
    todo = todo->next;
  }
}
