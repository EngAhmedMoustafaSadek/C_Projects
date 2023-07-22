#include "Queue.h"

static int queue[Queue_Size];
static int front = 0;
static int back = 0;
static int Queue_Count = 0;

queueStatus_t isFull(void)
{
    int status = Queue_Space;
    if (Queue_Count == Queue_Size)
    {
        status = Queue_Full;
    }
    return status;
}
queueStatus_t isEmpty(void)
{
    int status = Queue_Space;
    if (Queue_Count == 0)
    {
        status = Queue_Empty;
    }
    return status;
}
queueStatus_t enqueue(int data)
{
    int status = Queue_Full;
    if (isFull() != Queue_Full)
    {
        if (back == Queue_Size)
        {
            back = 0;
        }
        queue[back] = data;
        back++;
        Queue_Count++;
        status = Queue_Done;
    }
    return status;
}

queueStatus_t dequeue(int *data)
{
    int status = Queue_Empty;

    if (isEmpty() != Queue_Empty)
    {
        if (front == Queue_Size)
        {
            front = 0;
        }
        *data = queue[front];
        front++;
        Queue_Count--;
        status = Queue_Done;
    }
    return status;
}