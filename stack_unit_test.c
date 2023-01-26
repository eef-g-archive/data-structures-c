#include <stdio.h>
#include <stdlib.h>
#include "list_files/list.h"
#include "list_files/stack.h"

int main()
{
    // Set up the list to test
    Stackptr test_stack = Stack_new();
    int test_stack_values[] = {800, 77, 1, 40, 0, 15};
    for(int i = 0; i < 6; i++)
    {
        Stack_Push(test_stack, test_stack_values[i], INT);
    }

    // Testing to make sure head and tail pointers work
    if(test_stack->Stack_Backend->head->val == 800)
    {
        printf("Test 1 passed.\n");
    }
    else 
    { 
        printf("Test 1 failed! Expected '800', got '");
        Node_printVal(test_stack->Stack_Backend->head);
        printf("'\n");
    }

    if (test_stack->Stack_Backend->tail->val == 15)
    {
        printf("Test 2 passed.\n");
    }
    else
    {
        printf("Test 2 failed! Expected '15', got '");
        Node_printVal(test_stack->Stack_Backend->tail);
        printf("'\n");
    }

    // Test Finding a value
    if(List_findNodebyValue(test_stack, 0))
    {
        printf("Test 3 passed.\n");
    }
    else
    {
        printf("Test 3 failed! Could not find node with value '0' in list.\n");
    }

    // Test sorting by value
    List_valueSort(test_stack);
    if(test_stack->Stack_Backend->head->val == 0)
    {
        printf("Test 4 passed.\n");
    }
    else
    {
        printf("Test 4 failed! Expected '0', got '");
        Node_printVal(test_stack->Stack_Backend->head);
        printf("'\n");
    }
}