#include "list_files/stack.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
    printf("=-=-=-=-=-=-=- List Testing =-=-=-=-=-=-=-\n");
    Listptr test_list = List_new();
    int test_list_items[] = {57, 1, 55, 130, 16};
    for(int i = 0; i < 5; i++)
    {
        List_addValue(test_list, test_list_items[i], INT);
    }
    List_printList(test_list);
    List_valueSort(test_list);
    List_printList(test_list);

    test_list = NULL;
    printf("=-=-=-=-=-=-=- End List Testing =-=-=-=-=-=-=-\n");
}