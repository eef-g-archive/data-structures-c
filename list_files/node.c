// Author: Ethan Gray
// Purpose: Implementation of all the methods in the 'node.h' file

#include "node.h"
#include <stdio.h>
#include <stdlib.h>


/* Constructor Functions */
Nodeptr Node_new(int val, dataType type)
{
    Nodeptr n = (Nodeptr)malloc(sizeof(Node));
    Node_init(n, val, type);
    return n;
}

void Node_init(Nodeptr n, int val, dataType type)
{
    n->val = val;
    n->type = type;
}


/* Getters & Setters */
int Node_getValue(Nodeptr n)
{
    return n->val;
}

void Node_setValue(Nodeptr n, int val)
{
    n->val = val;
}

void Node_setNext(Nodeptr self, Nodeptr next)
{
    self->next = next;
}

/* Deconstructor */
void Node_reset(Nodeptr n) {}

void Node_destroy(Nodeptr n)
{
    if (n)
    {
        Node_reset(n);
        free(n);
    }

}





/*
    OLD NODE CODE
    - Uses previous OOP method
*/

// /* Node Methods */

// // Author: Ethan Gray
// // Purpose: This serves as an example of a getter method (However, at this moment I don't know how to set the protection of object's values)
// static int checkValue(struct Node *this)
// {
//     return this->val;
// }

// // Author: Ethan Gray
// // Purpose: This serves as an example of a setter method
// static void setNext(struct Node *this, struct Node* n)
// {
//     this->next = n;
// }

// // Author: Ethan Gray
// // Purpose: Prints out the 'object' to the terminal. (Ideally would want it to return the string, but idk how to do that yet.)
// static  void toString(struct Node *this)
// {
//     if (this->next != NULL)
//     {
//         printf("Node with value of '%d' that points to a node with value of '%d'\n", this->val, this->next->val);
//     }
//     else
//     {
//         printf("Node with value of '%d' with no next node.\n", this->val);
//     }
// }


// /* Node Constructor */
// static struct Node new(int value, int id)
// {
//     // In this return statement, we have the curly brackets
//     // This is beccause we need to assign SOMETHING to each item within the struct of our class object
//     // How do we assign each thing to that object?
//     //     - For the variables in the class, we do .<CLASS_VARIABLE_NAME>=<VALUE>
//     //     - For any methods, we do .<CLASS_METHOD_NAME>=<.C_METHOD_NAME>

//     // NOTE: For the mentioned assignments above, the <CLASS_METHOD_NAME> and <.C_METHOD_NAME> need to be the same name (Case Sensitive)
//     //       This is because we do not write the actual implementation of the function in the .h file, but in the .c file. 
//     //       And what this does essentially gives the object's struct the definition of the function by hooking it back up to the struct
//     return (struct Node)
//     {
//         .val=value,
//         .next=NULL,
//         .id=id,
//         // For functions, when you set it equal, do NOT in clude the '()' at the end of the function name.
//         .checkValue=checkValue,
//         .setNext=setNext,
//         .toString=toString
//     };
// }


// // This is what is run when we call the .new() function and allows for the actual creation of a new 'Object'
// const struct NodeClass Node={.new=new};
