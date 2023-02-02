//Purpose: Uses the 'list.h' Functions within renamed Stack Functions to make the Stack Data Structure

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
//Push Function: uses List Class Add Value Function
void Stack_Push(Stackptr self, void* val, dataType type)
{
    List_addValue(self->Stack_Backend, val, type);
}
//Pop Function: uses List Class Walk To IDX and Remove At Functions
void* Stack_Pop(Stackptr self)
{
    int len = self->Stack_Backend->len;
    int pop_idx = len - 1;
    void* node_val = List_walkToIndex(self->Stack_Backend, pop_idx) -> val;
    List_removeAt(self->Stack_Backend, pop_idx);
    return node_val;
}

//Find Node by Value Function: Uses List version of the function, but passes in a void* and a stack pointer(which is a list pointer)
void* Stack_findNodebyValue(Stackptr self, void* val)
{
    return List_findNodebyValue(self->Stack_Backend, val);
}

//Print function: Prints out the stack (in order from first value added to last)
void Stack_Print(Stackptr self)
{
    List_printList(self->Stack_Backend);
}
