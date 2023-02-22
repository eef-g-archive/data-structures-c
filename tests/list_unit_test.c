#include <stdio.h>
#include <stdlib.h>
#include "../headers/list.h"

int main()
{
    // Set up the list to test
    Listptr test_list = List_new();
    int test_list_values[] = {800, 77, 1, 40, 5, 0};
    for(int i = 0; i < 6; i++)
    {
        List_addValue(test_list, &test_list_values[i], INT);
    }

    printf("Starting list: ");
    List_printList(test_list);

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
    if (Node_getValue(test_list->tail) == 0)
    {
        printf("Test 2 passed. Valid Tail Node/Pointer Value\n");
    }
    else
    {
        printf("Test 2 failed! Expected '0', got '");
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
    if(Node_getValue(test_list->head) == 0)
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
    printf("Sorted list by value: ");
    List_printList(test_list);

    List_addressSort(test_list);
    if(Node_getValue(test_list->head) == 800)
    // Expecting it to be 800 bc that was the first value that was put into the list
    {
        printf("Test 5 passed. Successful Address Sort.\n");
    }
    else
    {
        printf("Test 5 failed! Unsuccessful Address Sort. Expected '0',  got '");
        Node_printVal(test_list->head);
        printf("\n");
    }
    printf("Sorted list by memory address: ");
    List_printList(test_list);

    List_removeAt(test_list, 0);
    if(Node_getValue(test_list->head) == 77)
    {
        printf("Test 6 Passed. Successfully removed value at head.\n");
    }
    else
    {
        printf("Test 6 failed! Unsuccessful removeAt call. Expected '77' got '");
        Node_printVal(test_list->head);
        printf("'\n");
    }

    List_removeAt(test_list, test_list->len - 1);
    if(Node_getValue(test_list->tail) == 5)
    {
        printf("Test 7 Passed. Successfully removed value at tail.\n");
    }
    else
    {
        printf("Test 7 failed! Unsuccessful removeAt call. Expected '5', got '");
        Node_printVal(test_list->tail);
        printf("'\n");
    }
    printf("List after removing head and tail: ");
    List_printList(test_list);

    // NOTE: In order to insert a value, the value must be declared somewhere else BEFORE being used as a pointer argument.
    // If you do not do that, it results in a memory issue
    int val_to_insert = 23;
    List_insertAfter(test_list, 2, &val_to_insert, INT);
    Nodeptr test_node = List_walkToIndex(test_list, 3);
    if(Node_getValue(test_node) == 23)
    {
        printf("Test 8 Passed. Successfully inserted value after specific index.\n");
    }
    else
    {
        printf("Test 8 failed! Unsuccessfully inserted value after specified index. Expected '23', received '");
        Node_printVal(test_node);
        printf("'\n");
    }
    printf("List after added value after index 2: ");
    List_printList(test_list);




    int val2_to_insert = 17;
    List_insertBefore(test_list, 2, &val2_to_insert, INT);
    test_node = List_walkToIndex(test_list, 2);
    if(Node_getValue(test_node) == 17)
    {
        printf("Test 9 Passed. Successfully inserted value before specified index.\n");
    }
    else
    {
        printf("Test 9 failed! Unsuccessfully inserted value before specified index. Expected '17', got '");
        Node_printVal(test_node);
        printf("'\n");
    }
    printf("List after adding value before index 2: ");
    List_printList(test_list);

    Nodeptr unlinked_node = List_unlinkNodebyValue(test_list, 17);
    if(Node_getValue(unlinked_node) == 17)
    {
        printf("Test 10 Passed. Successfully unlinked node after finding it based off of value.\n");
    }
    else
    {
        printf("Test 10 failed! Unsuccessfully unlinked node by finding it via value. Expected '17', got '");
        Node_printNode(unlinked_node);
        printf("'\n");
    }
    printf("List after unlinking value: ");
    List_printList(test_list);
    printf("If expected & actual outputs are the same: Test 11 Passed. Otherwise, Test 11 Failed.\n");

    List_clear(test_list);
    printf("Expected output: 'ERROR: List is empty'\n");
    printf("Actual output: ");
    List_printList(test_list);

    printf("List Destroy: \n");
    List_destroy(test_list);
    test_list = NULL;
    List_printList(test_list);
    //Address Boundary Error Shows that the Head pointer no longer exists and cannot be accessed
}
