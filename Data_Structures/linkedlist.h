#include <stdio.h>
#include <stdlib.h>

#define NULLPTR ((void *)0)

typedef struct node
{
    int data;

    struct node *next;
} node_t;

typedef enum
{
    LIST_EMPTY,
    NOT_FOUND,
    LIST_DONE
} listStatus_t;

node_t *CreateNode(int data);
void list_print(node_t *head);
node_t *list_addNoteToLast(node_t **phead, int data);
void list_addNoteToFirst(node_t **phead, int data);
listStatus_t list_editNode(node_t *head, int oldData, int data);
listStatus_t list_RemoveData(node_t **phead, int oldData);
listStatus_t list_insertAfter(node_t *head, int prevData, int data);
void list_printReverse(node_t *head);