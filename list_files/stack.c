//main stack file

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//Initializes the pointers and allocates memory
Stackptr Stack_new()
{
    Stackptr returnedPointer = (Stackptr)malloc(sizeof(Stack));
    Stack_init(returnedPointer);
    return returnedPointer;
}
//Constructor that uses List Class Functions
void Stack_init(Stackptr s)
{
    s->Stack_Backend = List_new(); //initializes a new stack, which uses the list function
}
//push function; uses List Class Add Value Function
void Stack_Push(Stackptr self, void* val, dataType type)
{
    List_addValue(self->Stack_Backend, val, type);
}
//pop function; uses List Class Walk To IDX and Remove At Functions
void* Stack_Pop(Stackptr self)
{
    int len = self->Stack_Backend->len;
    int pop_idx = len - 1;
    void* node_val = List_walkToIndex(self->Stack_Backend, pop_idx) -> val;
    List_removeAt(self->Stack_Backend, pop_idx);
    return node_val;
}

void Stack_Print(Stackptr self)
{
    List_printList(self->Stack_Backend);
}
