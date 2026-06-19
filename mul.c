#include "apc.h"

int mul(Dlist *list1_head, Dlist *list1_tail, Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Check if any operand list is empty
    if(list1_head == NULL || list2_head == NULL)
    {
        return FAILURE;
    }

    // Variable to keep track of zeros to append (place value shift)
    int shift = 0;

    // Traverse second number from tail to head
    while(list2_tail != NULL)
    {
        // Variable to store carry during multiplication
        int carry = 0;

        // Temporary linked list for intermediate multiplication result
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;

        // Temporary pointer for traversing first number
        Dlist *list1_temp_tail = list1_tail;

        // Multiply each digit of first number with current digit of second number
        while(list1_temp_tail != NULL)
        {
            // Multiply digits and add carry
            int product = (list1_temp_tail->data * list2_tail->data) + carry;

            // Update carry
            carry = product / 10;

            // Get current digit
            product = product % 10;

            // Insert digit at beginning of temporary list
            insert_first(&temp_head, &temp_tail, product);

            // Move to previous digit
            list1_temp_tail = list1_temp_tail->prev;
        }

        // Insert remaining carry if present
        if(carry)
        {
            insert_first(&temp_head, &temp_tail, carry);
        }

        // Add trailing zeros according to place value
        for(int i = 0; i < shift; i++)
        {
            // Create new node for zero
            Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

            // Check memory allocation
            if(newnode == NULL)
            {
                return FAILURE;
            }

            // Store zero in node
            newnode->data = 0;

            // Connect node at end of list
            newnode->prev = temp_tail;
            newnode->next = NULL;

            // Link node to list
            if(temp_tail)
            {
                (temp_tail)->next = newnode;
            }
            else
            {
                temp_head = newnode;
            }

            // Update tail
            temp_tail = newnode;
        }
        // New result list after addition
        Dlist *new_head = NULL;
        Dlist *new_tail = NULL;
        // Add temporary result with previous result
        add(temp_head, temp_tail, *res_head, *res_tail, &new_head, &new_tail);
        // Update result list
        *res_head = new_head;
        *res_tail = new_tail;
        // Increment shift for next iteration
        shift++;
        // Move to previous digit of second number
        list2_tail = list2_tail->prev;
    }

    // Remove leading zeros from result
    while(*res_head != NULL && (*res_head)->data == 0 && *res_head != *res_tail)
    {
        // Store current head node
        Dlist *temp = *res_head;
        // Move head to next node
        *res_head = (*res_head)->next;
        // Update previous pointer
        (*res_head)->prev = NULL;
        // Free removed node
        free(temp);
    }
    return SUCCESS;
}