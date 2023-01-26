#include "list_files/stack.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{

    printf("=-=-=-=-=-=-=- Stack Testing =-=-=-=-=-=-=-\n");
    Stackptr test_stack = Stack_new();
    printf("Stack Made\n");

    Stack_Push(test_stack, (void*)25); 
    printf(test_stack->Stack_Backend->len);
    Stack_Print(test_stack);
        
    printf("=-=-=-=-=-=-=- End Stack Testing =-=-=-=-=-=-=-\n");
}