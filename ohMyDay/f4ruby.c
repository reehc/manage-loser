#include "queue.h"
#include <stdio.h>

queue_t *q = NULL;

void init()
{
    q = q_new();
    if (q == NULL) printf("Unable to create a queue.\n");
    else printf("Created.\n");   
}

/* I define this function 'free()' first, and I am bugged.  */
void freeQ()
{
    q_free(q);
}

void show()
{
    if (q == NULL) printf("Init first.\n");
    else if (q->head == NULL) printf("[]");
    else
    {
        int i;
 	list_ele_t *temp = q->head;
        printf("[");
	for (int i = 0; i < q->size; i++)
	{
	    printf("%d,", temp->value);
	    temp = temp->next;
	}
	printf("\b]\n");
    }
}

void ih(int i)
{
    bool result = q_insert_head(q, i);
    if (result) show();
    else printf("Unable to insert head.\n");
}

void it(int i)
{
    bool result = q_insert_tail(q, i);
    if (result) show();
    else printf("Unable to insert tail.\n");
}

void rh()
{
    bool result = q_remove_head(q, NULL);
    if (result) show();
    else printf("Ubable to remove head.\n");
}

int size()
{
    return q_size(q);
}

void reverse()
{
    q_reverse(q);
    show();
}

int main()
{
    init();
    ih(1);
    it(5);
    rh();
}
