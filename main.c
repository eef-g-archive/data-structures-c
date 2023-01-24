#include "list_files/list.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
    printf("=-=-=-=-=-=-=- List Testing =-=-=-=-=-=-=-\n");
    int listVals[5] = {13, 25, 7, 18, 2};
    Listptr test_list = List_new();
    for(int i = 0; i < 5; i++)
    {
        List_addValue(test_list, listVals[i], INT);
    }

    Nodeptr test_node = List_findNodebyValue(test_list, 7);
    printf("Here's the node value from the node we found: ");
    Node_printVal(test_node);
    printf("\n");

    List_destroy(test_list);
    test_list = NULL;
    printf("=-=-=-=-=-=-=- End List Testing =-=-=-=-=-=-=-\n");
}