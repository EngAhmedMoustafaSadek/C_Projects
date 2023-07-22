#define Queue_Size 5

typedef enum
{
    Queue_Full,
    Queue_Empty,
    Queue_Space,
    Queue_Done
} queueStatus_t;

queueStatus_t enqueue(int data);
queueStatus_t dequeue(int *data);
queueStatus_t isFull(void);
queueStatus_t isEmpty(void);