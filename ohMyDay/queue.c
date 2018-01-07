/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

//#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q)
    {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
    if (q == NULL) return; 
    else if(q->head == NULL) {}
    else {
        list_ele_t *temp;
        while (q->head != NULL) {
            temp = q->head;
            q->head = q->head->next;
            free(temp);
        }
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (q == NULL) return false;
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if (newh == NULL) return false;
    if (q->size > 0) {
        newh->value = v;
        newh->next = q->head;
        q->head = newh;
    } else if (q->size == 0)
    {
        newh->value = v;
        newh->next = NULL;
        q->head = newh;
        q->tail = newh;
    } else {
        printf("What this operation is ?\n");
        exit(1);
    }
    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (q == NULL) return false;
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if (newh == NULL) return false;
    if (q->size > 0) {
        newh->value = v;
        newh->next = NULL;
        q->tail->next = newh;
        q->tail = newh;
    } else if (q->size == 0)
    {
        newh->value = v;
        newh->next = NULL;
        q->head = newh;
        q->tail = newh;
    } else {
        printf("What this operation is ?\n");
        exit(1);
    }
    q->size++;
    return true;
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if (q == NULL || q->head == NULL) return false;
    if (vp != NULL) *vp = q->head->value;
    if (q->size > 1)
    {
        list_ele_t *temp = q->head;
        q->head = q->head->next;
        free(temp);
        q->size--;
    } else if (q->size == 1) {
        list_ele_t *temp = q->head;
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
        free(temp);
    } else {
        printf("What this operation is ?\n");
        exit(1);
    }
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL || q->head == NULL) return 0;
    else return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q_size(q) > 1){
        list_ele_t *eles[q->size];
        list_ele_t *temp = q->head;
        int i;
        for (i = 0; i < q->size; ++i)
        {
            eles[i] = temp;
            temp = temp->next;
        }
        for (i = q->size - 1; i > 0; --i)
        {
            eles[i]->next = eles[i-1];
        }
        eles[0]->next = NULL;
        q->head = eles[q->size - 1];
        q->tail = eles[0];
    }
}

