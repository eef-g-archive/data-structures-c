#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"

int main()
{
    // Set up the list to test
    Stackptr test_stack = Stack_new();
    int test_stack_values[] = {800, 77, 1, 40, 0, 15};
    for(int i = 0; i < 6; i++)
    {
        Stack_Push(test_stack, &test_stack_values[i], INT);
    }
    
    // Head Pointer
    if(Node_getValue(test_stack->Stack_Backend->head) == 800)
    {
        printf("Test 1 Passed: Valid Head Node/Pointer\n");
    }
    else 
    { 
        printf("Test 1 failed! Expected '800', got '");
        Node_printVal(test_stack->Stack_Backend->head);
        printf("'\n");
    }
    
    //Tail Pointer
    if (Node_getValue(test_stack->Stack_Backend->tail) == 15)
    {
        printf("Test 2 Passed: Valid Tail Node/Pointer\n");
    }
    else
    {
        printf("Test 2 failed! Expected '15', got '");
        Node_printVal(test_stack->Stack_Backend->tail);
        printf("'\n");
    }

    // Pop Unit Test
    if(Stack_Pop(test_stack) == 15)
    {
        printf("Test 3 Passed: Pop Function\n");
    }
    else
    {
        printf("Test 3 Failed");
    }

    //Push Unit Test
    int test_val = 15;
    Stack_Push(test_stack, &test_val, INT);
    if(test_stack->Stack_Backend->len == 6)
    {
        printf("Test 4 Passed: Push Function\n");
    }
    else
    {
        printf("Test 4 Failed: Did not push value to Stack\n");
    }

    // Test Finding a value
    if(Stack_findNodebyValue(test_stack, 0))
    {
        printf("Test 5 Passed: Find Node by Value\n");
    }
    else
    {
        printf("Test 5 failed! Could not find node with value '0' in list.\n");
    }

    //Tests Functionality of Stack Print AND shows if Stack_Push was successful
    Stack_Print(test_stack);
}
