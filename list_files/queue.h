#ifndef QUEUE_H

#define QUEUE_H
#include <stdlib.h>
#include "list.h"

typedef struct Queue
{
    /* data */
    Listptr queueBackend;
} Queue, * Queueptr;


Queueptr Queue_new();
void Queue_init(Queueptr q);
void Queue_enqueue(Queueptr self, void* val);
void* Queue_dequeue(Queueptr self);
void Queue_clear(Queueptr self);
void Queue_destroy(Queueptr self);

#endif
