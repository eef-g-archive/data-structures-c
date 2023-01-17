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
void List_addValue(Listptr self, int val)
{
    // First, make the node
    Nodeptr n = Node_new(val);

    if(self->len == 0)
    {
        self->head = n;
        self->tail = n;
    }
    else
    {
        Node_setNext(self->tail, n);
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
                printf("%d, ",Node_getValue(n));
            }
            else
            {
                printf("%d ", Node_getValue(n));
            }
            n = n->next;
        }
        printf("]\n");
    }
    else
    {
        printf("ERROR: List is empty");
    }
}

void List_insert(Listptr self, int index, int val)
{
    Nodeptr node = Node_new(val);
    Nodeptr listNode = List_walkToIndex(self, index - 1);
    node->next = listNode->next;
    listNode->next = node;
    self->len++;
}



// removeAt works, however need to figure out how to make it work if you removeAt the start of the list

void List_removeAt(Listptr self, int index)
{
    if (index != 0)
    {
        Nodeptr del = List_walkToIndex(self, index);
        Nodeptr delPrev = List_walkToIndex(self, index-1);
        delPrev->next = del->next;
        Node_destroy(del);
        self->len--;
    }
    else
    {
        Nodeptr temp = self->head;
        Node_destroy(self->head);
        self->head = temp;
        self->len--;
    }
}




/*
    OLD LIST CODE
    - Uses old OOP method
*/


// /* List Methods */
// void addValue(struct List *this, int val)
// {
//     printf("=-=-=-=-=- ADD VALUE FUNCTION =-=-=-=-=-\n");
//     struct Node n = Node.new(val, this->len);
//     printf("New node from addValue function: ");
//     n.toString(&n);
//     printf("Current 'len' value: %d\n", this->len);
//     if(this->len == 0)
//     {
//         printf("Initializing list by adding a new head.\n");
//         this->head = &n;
//     }
//     else
//     {
//         printf("Updating tail.\n");
//         if(this->tail == NULL)
//         {
//             this->tail = &n;
//             this->head->next = this->tail;
//         }
//         else
//         {
//             this->tail->next = &n;
//             this->tail = &n;
//         }
//     }

//     printf("Current head ID: %d\n", this->head->id);
//     printf("Current tail ID: ");
//     if(this->tail == NULL)
//     {
//         printf("No current tail.\n");
//     }
//     else
//     {
//         printf("%d\n",this->tail->id);   
//     }
//     printf("=-=-=-=-=- END FUNCTION =-=-=-=-=-\n");
//     this->len++;
// }

// void printList(struct List *this)
// {
//     struct Node* n = this->head;

//     struct Node curr;
//     //printf("[ ");
//     int out = 0;
//     for(int i = 0; i < this->len; i++)
//     {
//         // Print out current node info
//         printf("Current n info: ");
//         curr = *n;
//         curr.toString(&curr);
//         // First, convert the int* to an int

//     /* EGEGEGEGEGEGEGEGEGEGEGEGEGEGEG
    
//     NOTES:
//     * Everything "Works" logically
//     * Need to figure out how to make the node STAY in memory after making it in the function (probablly using malloc or something like that)
//     * Once Node stays in memory, need to work on converting the value of the node from a pointer to an actual int
    
//     EGEGEGEGEGEGEGEGEGEGEGEGEGEGEG */



//         out = n->val;
//         if(i != this->len - 1)
//         {
//             //printf("%d, ", out);
//         }
//         else
//         {
//             //printf("%d ", out);
//         }
//         n = n->next;
//     }
//     //printf("]\n");
// }

// /* List Constructor */
// static struct List new()
// {

//     // In this return statement, we have the curly brackets
//     // This is beccause we need to assign SOMETHING to each item within the struct of our class object
//     // How do we assign each thing to that object?
//     //     - For the variables in the class, we do .<CLASS_VARIABLE_NAME>=<VALUE>
//     //     - For any methods, we do .<CLASS_METHOD_NAME>=<.C_METHOD_NAME>

//     // NOTE: For the mentioned assignments above, the <CLASS_METHOD_NAME> and <.C_METHOD_NAME> need to be the same name (Case Sensitive)
//     //       This is because we do not write the actual implementation of the function in the .h file, but in the .c file. 
//     //       And what this does essentially gives the object's struct the definition of the function by hooking it back up to the struct
//     return (struct List)
//     {
//         // Struct Variables
//         .head=NULL,
//         .tail=NULL,
//         .len=0,
//         // Struct Functions
//         // For functions, when you set it equal, do NOT in clude the '()' at the end of the function name.
//         .addValue=addValue,
//         .printList=printList
//     };
// }


// // This is what is run when we call the .new() function and allows for the actual creation of a new 'Object'
// const struct ListClass List={.new=new};
