// Author: Ethan Gray
// Purpose: Implementation of all the methods in the 'list.h' file to make a Linked List

#include "node.h"
#include "list.h"
#include <stdio.h>
#include <stdint.h>

/* Constructor */
Listptr List_new()
{
    Listptr l = (Listptr)malloc(sizeof(List));
    List_init(l);
    return l;
}

void List_init(Listptr l)
{
    l->len=0;
}

/* Getters & Setters */
void List_addValue(Listptr self, void* val, dataType type)
{
    // First, make the node
    Nodeptr n = Node_new(val, type);

    if(self->len == 0)
    {
        self->head = n;
        self->tail = n;
    }
    else
    {
        Node_setNext(self->tail, n);
        n->prev = self->tail;
        self->tail = n;
    }
    self->len++;
}


/* Other Methods */

Nodeptr List_walkToIndex(Listptr self, int index)
{
    Nodeptr curr = self->head;

    // Will add an "Out of Index" error if it's too large or small.

    for(int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr;
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
    Nodeptr node = Node_new(val, type);
    Nodeptr listNode = List_walkToIndex(self, index - 1);
    node->next = listNode->next;
    listNode->next = node;
    self->len++;
}




void List_removeAt(Listptr self, int index)
{
    // Check to make sure we're not removing the head of the list
    if (index != 0)
    {
        Nodeptr del = List_walkToIndex(self, index);
        Nodeptr delPrev = del->prev;
        delPrev->next = del->next;
        Node_destroy(del);
        if(index == self->len)
        {
            self->tail = delPrev;
        }
    }
    // If we are, then make the precautions needed
    else
    {
        Nodeptr del = List_walkToIndex(self, index);
        if(self->len > 1)
        {
            self->head = del->next;
        }
        else
        {
            self->head = NULL;
            self->tail = NULL;
        }
        Node_destroy(del);
        del = NULL;
    }
    self->len--;
}

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