#include "list_files/list.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
    printf("=-=-=-=-=-=-=- Node Testing =-=-=-=-=-=-=-\n");
    Nodeptr n1 = Node_new(15, INT);
    Nodeptr n2 = Node_new(24, INT);
    Node_setNext(n1, n2);
    printf("Here's the value of n1: %d\nHere's the value of n2: %d\n",Node_getValue(n1), Node_getValue(n2));
    printf("Here's the value of n1's next node: %d\n",n1->next->val);

   
    // Now that we're done with this, we want to destroy the nodes & null out the variables
    Node_destroy(n1);
    Node_destroy(n2);
    n1 = NULL;
    n2 = NULL;
    printf("=-=-=-=-=-=-=- End Node Testing =-=-=-=-=-=-=-\n\n\n");

    printf("=-=-=-=-=-=-=- List Testing =-=-=-=-=-=-=-\n");
    int listVals[5] = {13, 25, 7, 18, 2};
    Listptr l = List_new();
    for(int i = 0; i < 5; i++)
    {
        List_addValue(l, listVals[i], INT);
    }
    List_addValue(l, "Hello!", STRING);
    List_printList(l);

    // How to add a double to the list (It's really weird bc of the void*)
    double x = 3.5; // Step 1: Have your double variable
    List_addValue(l, &x, DOUBLE); // Step 2: Pass in a POINTER to the function
    // ^^ For this line, we use '&x' because the '&' lets the compiler know it's a pointer
    // We use the pointer for a few reasons:
    /*
        1) The compiler errors out when you use a double and not a double pointer
        2) The way doubles are stored in memory is completely different from how the void* data type works
           Because of this, we simply cannot pass a double straight to the list if it uses a void* for generics
    */
    List_printList(l);


    List_destroy(l);
    l = NULL;
    printf("=-=-=-=-=-=-=- End List Testing =-=-=-=-=-=-=-\n");
}