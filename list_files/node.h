#ifndef NODE_H

#define NODE_H
#include <stdlib.h>

typedef enum {INT, CHAR, STRING, DOUBLE} dataType;

typedef struct Node
{
    /* data */
    void* val;
    struct Node* next;
    struct Node* prev;
    dataType type;
} Node;


typedef Node * Nodeptr;


/* functions */
Nodeptr Node_new(int val, dataType type);
void Node_init(Nodeptr n, int val, dataType type);
int Node_getValue(Nodeptr n);
void Node_setValue(Nodeptr n, int value);
void Node_setNext(Nodeptr self, Nodeptr next);
void Node_reset(Nodeptr n);
void Node_destroy(Nodeptr n);

#endif