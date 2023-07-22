#include "stack.h"

stack_t *stack_create(void)
{
    stack_t *s = malloc(sizeof(stack_t));
    s->stackhead = NULLPTR;
    s->sp = s->stackhead;
}

stackStatus_t stack_delete(STACKPTR_T stack)
{
    int *tempdata;
    stackStatus_t status = STACK_EMPTY;
    while (stack->sp != stack->stackhead)
    {
        status = pop(stack, tempdata);
    }
    return status;
}

void push(STACKPTR_T stack, int data)
{
    stack->sp = list_addNoteToLast(&(stack->stackhead), data);
}

stackStatus_t pop(STACKPTR_T stack, int *pdata)
{
    node_t *current = stack->stackhead;
    node_t *temp;
    if (stack->stackhead == NULLPTR)
    {
        return STACK_EMPTY;
    }
    else
    {
        while (current->next != stack->sp)
        {
            current = current->next;
        }
        *pdata = stack->sp->data;
        temp = stack->sp;
        stack->sp = current;
        if (current == stack->stackhead)
        {
            stack->stackhead = NULLPTR;
        }
        else
        {
            current->next = NULLPTR;
        }
        free(temp);
        return STACK_DONE;
    }
}
