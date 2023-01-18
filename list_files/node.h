#ifndef NODE_H

#define NODE_H
#include <stdlib.h>

typedef struct Node
{
    /* data */
    void* val;
    struct Node* next;
    struct Node* prev;
} Node;



typedef Node * Nodeptr;


/* functions */
Nodeptr Node_new(int val);
void Node_init(Nodeptr n, int val);
int Node_getValue(Nodeptr n);
void Node_setValue(Nodeptr n, int value);
void Node_setNext(Nodeptr self, Nodeptr next);
void Node_reset(Nodeptr n);
void Node_destroy(Nodeptr n);



#endif