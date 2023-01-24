//main stack file

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//constructor function
Stackptr Stack_new()
{
    Stackptr returnedPointer = (Stackptr)malloc(sizeof(Stack));
    Stack_init(returnedPointer);
    return returnedPointer;
}
void Stack_init(Stackptr s)
{
    s->Stack_Backend = List_new(); //initializes a new stack, which uses the list function
}
//push function
void Stack_Push(Stackptr self, void* val)
{
    List_addValue(self->Stack_Backend, val, INT);
}
//pop function
void* Stack_Pop(Stackptr self)
{
    int len = self->Stack_Backend->len;
    int pop_idx = len - 1;
    void* node_val = List_walkToIndex(self->Stack_Backend, pop_idx) -> val;
    List_removeAt(self->Stack_Backend, pop_idx);
    return node_val;
}

