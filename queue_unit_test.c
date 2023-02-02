#include <stdio.h>
#include <stdlib.h>
#include "list_files/queue.h"

int main()
{
    Queueptr test_queue = Queue_new();
    int test_queue_values[] = {800, 77, 1, 40, 0, 15};
    for(int i = 0; i < 6; i++)
    {
        Queue_enqueue(test_queue, test_queue_values[i]);
    }

    void* dequeue_output1 = Queue_dequeue(test_queue);
    void* dequeue_output2 = Queue_dequeue(test_queue);

    //Initial Dequeue
    if(dequeue_output1 == 800)
    {
        printf("Test 1 passed.\n");
    }    
    else
    {
        printf("Test 1 failed. Expected '800', got '%d'\n", dequeue_output1);
    }

    //Second Dequeue
    if(dequeue_output2 == 77)
    {
        printf("Test 2 passed.\n");
    }
    else
    {
        printf("Test 2 failed. Expected '77', got '%d'\n", dequeue_output2);
    }

    
    
}
