#include "apc.h"

int sub(Dlist *list1_head, Dlist *list1_tail, Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Variable to store borrow during subtraction
    int borrow = 0;

    // Subtract digits while both lists have elements
    while(list1_tail != NULL && list2_tail != NULL)
    {
        // Get current digit from first number after subtracting borrow
        int num1 = list1_tail->data - borrow;

        // Get current digit from second number
        int num2 = list2_tail->data;

        // Check if borrow is needed
        if(num1 < num2)
        {
            // Add 10 to current digit
            num1 = num1 + 10;

            // Set borrow for next digit
            borrow = 1;
        }
        else
        {
            // No borrow required
            borrow = 0;
        }

        // Calculate difference
        int difference = num1 - num2;

        // Move to previous digit in first list
        list1_tail = list1_tail->prev;

        // Move to previous digit in second list
        list2_tail = list2_tail->prev;

        // Insert result digit at beginning of result list
        if(insert_first(res_head, res_tail, difference) == FAILURE)
        {
            return FAILURE;
        }
    }

    // Process remaining digits of first list
    while(list1_tail != NULL)
    {
        // Subtract borrow from current digit
        int difference = list1_tail->data - borrow;

        // Check if borrow is needed
        if(difference < 0)
        {
            // Add 10 to current digit
            difference = difference + 10;

            // Set borrow for next digit
            borrow = 1;
        }
        else
        {
            // No borrow required
            borrow = 0;
        }

        // Move to previous digit
        list1_tail = list1_tail->prev;

        // Insert result digit into result list
        if(insert_first(res_head, res_tail, difference) == FAILURE)
        {
            return FAILURE;
        }
    }

    // Remove leading zeros from result
    while(*res_head != NULL && (*res_head)->data == 0 && *res_head != *res_tail)
    {
        // Store node to delete
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