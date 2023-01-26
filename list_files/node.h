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
    int size;
} Node;


typedef Node * Nodeptr;

/* functions */
Nodeptr Node_new(void* val, dataType type);
void Node_init(Nodeptr self, void* val, dataType type);
void* Node_getValue(Nodeptr self);
void Node_setValue(Nodeptr self, void* val);
void Node_setNext(Nodeptr self, Nodeptr next);
void Node_reset(Nodeptr self);
void Node_destroy(Nodeptr self);
void Node_printVal(Nodeptr self);
void Node_printNode(Nodeptr self);

#endif
