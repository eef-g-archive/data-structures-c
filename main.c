#include "list_files/list.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
    printf("=-=-=-=-=-=-=- Node Testing =-=-=-=-=-=-=-\n");
    Nodeptr n1 = Node_new(15);
    Nodeptr n2 = Node_new(24);
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
    Listptr l = List_new();
    List_addValue(l, 13);
    List_addValue(l, 25);
    List_addValue(l, 7);
    List_printList(l);
    List_removeIndex(l, 1);
    List_printList(l);
}