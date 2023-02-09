#include <stdio.h>
#include <stdlib.h>
#include "list_files/list.h"

int main()
{
    // Set up the list to test
    Listptr test_list = List_new();
    int test_list_values[] = {800, 77, 1, 40, 5, 0};
    for(int i = 0; i < 6; i++)
    {
        List_addValue(test_list, &test_list_values[i], INT);
    }


    // Head Pointer
    if(Node_getValue(test_list->head) == 800)
    {
        printf("Test 1 passed. Valid Head Node/Pointer Value\n");
    }
    else 
    { 
        printf("Test 1 failed! Expected '800', got '");
        Node_printVal(test_list->head);
        printf("'\n");
    }

    // Tail Pointer
    if (Node_getValue(test_list->tail) == 16)
    {
        printf("Test 2 passed. Valid Tail Node/Pointer Value\n");
    }
    else
    {
        printf("Test 2 failed! Expected '15', got '");
        Node_printVal(test_list->tail);
        printf("'\n");
    }

    // Test Finding a value
    if(List_findNodebyValue(test_list, 0))
    {
        printf("Test 3 passed. Successful Find Node by Value\n");
    }
    else
    {
        printf("Test 3 failed! Could not find node with value '0' in list.\n");
    }

    // Value Sort
    List_valueSort(test_list);
    if(test_list->head->val == 0)
    {
        printf("Test 4 Passed. Successful Value Sort\n");
    }
    else
    {
        printf("Test 4 failed! Expected '0', got '");
        Node_printVal(test_list->head);
        printf("'\n");
    }

    //Address Sort Unit Test

    //Print List AND addList Accuracy/Validity Test
    List_printList(test_list);
}
