#include <stdio.h>
#include "queue.h"
#include "list.h"

/* Constructor */

Queueptr Queue_new()
{
    Queueptr returnedPointer = (Queueptr)malloc(sizeof(Queue));
    Queue_init(returnedPointer);
    return returnedPointer;
}

void Queue_init(Queueptr q)
{
    q->queueBackend = List_new();
}

void Queue_enqueue(Queueptr self, void* val)
{
    List_addValue(self->queueBackend, val, INT);
}

void* Queue_dequeue(Queueptr self)
{
    void* node_val = self->queueBackend->head->val;
    List_removeAt(self->queueBackend, 0);
    return node_val;
}
