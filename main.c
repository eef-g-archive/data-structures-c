#include "list_files/list.h"
#include <stdio.h>
#include<stdlib.h>

void testEmptyList(Listptr l);
void testCreateList(Listptr l, int vals[]);

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
    int listVals[5] = {13, 25, 7, 18, 2};
    Listptr l = List_new();
    testCreateList(l, listVals);
    testEmptyList(l);
    testCreateList(l, listVals);
    printf("=-=-=-=-=-=-=- End List Testing =-=-=-=-=-=-=-\n");
}

void testEmptyList(Listptr l)
{
    printf("[Empty List Test] Starting List: ");
    List_printList(l);
    int i = 0;
    while(l->len > 0)
    {
        printf("| ");
        List_removeAt(l, 0);
        List_printList(l);
        i++;
    }
}


void testCreateList(Listptr l, int vals[])
{
    printf("[Adding Values test] Starting List: ");
    List_printList(l);
    for(int i = 0; i < 5; i++)
    {
        printf("| ");
        List_addValue(l, vals[i]);
        List_printList(l);
    }
}