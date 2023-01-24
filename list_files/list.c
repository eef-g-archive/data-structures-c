// Purpose: Implementation of all the methods in the 'list.h' file to make a Linked List

#include "node.h"
#include "list.h"
#include <stdio.h>
#include <stdint.h>

/* Constructor */
Listptr List_new()
{
    Listptr returnedPointer = (Listptr)malloc(sizeof(List));
    List_init(returnedPointer);
    return returnedPointer;
}

void List_init(Listptr l)
{
    l->len=0;
}

/* Getters & Setters */
void List_addValue(Listptr self, void* val, dataType type)
{
    // First, make the node
    Nodeptr newNode = Node_new(val, type);

    if(self->len == 0)
    {
        self->head = newNode;
        self->tail = newNode;
    }
    else
    {
        Node_setNext(self->tail, newNode);
        newNode->prev = self->tail;
        self->tail = newNode;
    }
    self->len++;
}


/* Other Methods */

Nodeptr List_walkToIndex(Listptr self, int index)
{
    Nodeptr currentNode = self->head;

    for(int i = 0; i < index; i++)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

void List_printList(Listptr self)
{
    if(self->len > 0)
    {
        printf("[ ");
        Nodeptr n = self->head;
        for(int i = 0; i < self->len; i++)
        {
            if(i != self->len-1)
            {
                Node_printVal(n);
                printf(", ");
            }
            else
            {
                Node_printVal(n);
            }
            n = n->next;
        }
        printf("]\n");
    }
    else
    {
        printf("ERROR: List is empty\n");
    }
}

void List_insert(Listptr self, int index, void* val, dataType type)
{
    Nodeptr newNode = Node_new(val, type);
    Nodeptr nodeAtIndex = List_walkToIndex(self, index - 1);
    newNode->next = nodeAtIndex->next;
    nodeAtIndex->next = newNode;
    self->len++;
}




void List_removeAt(Listptr self, int index)
{
    // Check to make sure we're not removing the head of the list
    if (index != 0)
    {
        Nodeptr nodeToDelete = List_walkToIndex(self, index);
        Nodeptr previousNode = nodeToDelete->prev;
        previousNode->next = nodeToDelete->next;
        Node_destroy(nodeToDelete);
        if(index == self->len)
        {
            self->tail = previousNode;
        }
    }
    // If we are, then make the precautions needed
    else
    {
        Nodeptr nodeToDelete = List_walkToIndex(self, index);
        if(self->len > 1)
        {
            self->head = nodeToDelete->next;
        }
        else
        {
            self->head = NULL;
            self->tail = NULL;
        }
        Node_destroy(nodeToDelete);
        nodeToDelete = NULL;
    }
    self->len--;
}

Nodeptr List_findNodebyValue(Listptr self, void* val)
{
    Nodeptr currentNode = self->head;
    for(int i = 0; i < self->len; i++)
    {
        if (currentNode->val == val)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

// For sorting: 
/*
    - Will want to keep track of the address of the data in a node
    - These addresses give us normal integers (technically)
    - We use those addresses to sort the values based off of where they are in memory
    - We'll only need this type of sorting because that's what the memory manager is going to use

    -- OTHER WAY:
     - Look at the value of the data in the node
     - Sort by value of the data (This requires you to have a way to compare all types of data if the list is mixed)
*/


/* Deconstructors */

void List_clear(Listptr self)
{
    while(self->head->next != NULL)
    {
        List_removeAt(self, 0);
    }
    List_removeAt(self, 0);
}

void List_destroy(Listptr self)
{
    if(self)
    {
        List_clear(self);
        free(self);
    }
}