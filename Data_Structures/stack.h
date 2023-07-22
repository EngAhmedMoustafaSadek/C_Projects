#define STACK_SIZE 5
#include "linkedlist.h"

typedef struct
{
    node_t *sp;
    node_t *stackhead;

} stack_t;

typedef stack_t *STACKPTR_T;

typedef enum
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_DONE
} stackStatus_t;

node_t *list_addNoteToLast(node_t **phead, int data);
stack_t *stack_create(void);
stackStatus_t stack_delete(STACKPTR_T stack);
void push(STACKPTR_T stack, int data);
stackStatus_t pop(STACKPTR_T stack, int *pdata);