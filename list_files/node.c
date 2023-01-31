// Purpose: Implementation of all the methods in the 'node.h' file

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Constructor Functions */
Nodeptr Node_new(void* val, dataType type)
{
    Nodeptr returnedPointer = (Nodeptr)malloc(sizeof(Node));
    Node_init(returnedPointer, val, type);
    return returnedPointer;
}

void Node_init(Nodeptr self, void* val, dataType type)
{
    self->val = val;
    self->type = type;
    self->size = sizeof(val);
}

/* Getters & Setters */

// Returns the data stored in self->val
void* Node_getValue(Nodeptr self)
{
    return self->val;
}

// Changes the data stored in self->val and also updates the self->size value
void Node_setValue(Nodeptr self, void* val)
{
    self->val = val;
    self->size = sizeof(val);
}


/* Misc Functions */

// Prints the value of the node depending on the type variable
void Node_printVal(Nodeptr self)
{
    switch (self->type)
    {
        case INT:
        {
            /* code */
            printf("%d", (int*)self->val); //casts void* val ptr to int*, then dereferences (tells me what the pointer is pointing at)
            break;
        }
        case STRING:
        {
            printf("%s", (char*)self->val);
            break;
        }
        case CHAR:
        {
            printf("%c", (char*)self->val);
            break;
        }
        case DOUBLE:
        {
            double *temporaryDoublePointer = self->val;
            double temporaryDoubleStorage = *temporaryDoublePointer;
            printf("%.2f", temporaryDoubleStorage);
            break;
        }
        default:
        {
            break;
        }
    }
}

void Node_printNode(Nodeptr self)
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("| Node with value: ");
    Node_printVal(self);
    printf("\n| Next pointer: ");
    if(self->next != NULL)
    {
        printf("Node with value [");
        Node_printVal(self->next);
        printf("]\n");
    }
    else
    {
        printf("NULL\n");
    }

    printf("| Prev pointer: ");
    if(self->prev != NULL)
    {
        printf("Node with value [");
        Node_printVal(self->prev);
        printf("]\n");
    }
    else
    {
        printf("NULL\n");
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

/* Deconstructor */
void Node_reset(Nodeptr self) {} 

void Node_destroy(Nodeptr self)
{
    if (self)
    {
        Node_reset(self);
        free(self);
    }
}
