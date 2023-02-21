// Purpose: Implementation of all the methods in the 'node.h' file

#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Constructor Functions */

// Create a new node object on the heap and return a Nodeptr to that Node
Nodeptr Node_new(void* val, dataType type)
{
    Nodeptr returnedPointer = (Nodeptr)malloc(sizeof(Node));
    Node_init(returnedPointer, val, type);
    return returnedPointer;
}

// Initialize the values within the node object
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
    void* output = NULL;
    switch (self->type)
    {
        case INT:
        {
            output = *(int *)self->val;
            break;
        }
        case STRING:
        {
            output = (char*)self->val;
            break;
        }
        case CHAR:
        {
            output = *(char *)self->val;
            break;
        }
        case DOUBLE:
        {
            //printf("%.2f", *(double*)self->val);
            output = self->val;
            break;
        }
        case POINTER:
        {
            output = self->val;
        }
        default:
        {
            break;
        }
    }
    return output;
}

// Changes the data stored in self->val and also updates the self->size value
void Node_setValue(Nodeptr self, void* val)
{
    
    // RN no wayh to set size for pointers`
    self->val = val;
    self->size = sizeof(val);
    // Know the data type, so if string then
    // Use strlen(val) + 1 <-- Gives the length of the string & Terminating NULL
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
            printf("%d", *(int*)self->val); //casts void* val ptr to int*, then dereferences (tells me what the pointer is pointing at)
            break;
        }
        case STRING:
        {
            printf("%s", (char*)self->val);
            break;
        }
        case CHAR:
        {
            printf("%c", *(char*)self->val);
            break;
        }
        case DOUBLE:
        {
            //printf("%.2f", *(double*)self->val);
            double *temporaryDoublePointer = self->val;
            double temporaryDoubleStorage = *temporaryDoublePointer;
            printf("%.2f", temporaryDoubleStorage);
            break;
        }
        case POINTER:
        {
            printf("%p", self->val);
        }
        default:
        {
            break;
        }
    }
}

// Print out all the data within the node to the terminal. Mainly used for debugging purposes.
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

// Make all values of the node = NULL
void Node_reset(Nodeptr self)
{
    self->next = NULL;
    self->prev = NULL;
    self->size = NULL;
    // If val is actually a pointer, if you set it to NULL
    // You lose the pointer that points to the value itself, but not free the data somewhere else
    // Make sure that it manually frees the node->val just in case.

    // OTHER SOLUTION:
    /*
        Add a new variable into the node that is a pointer to the clearnup function
        In reset, call the clearnup function on self->val
    */
    self->val = NULL;
} 

// Clear out the node's data and then free the struct from memory
void Node_destroy(Nodeptr self)
{
    if (self)
    {
        Node_reset(self);
        free(self);
    }
}
