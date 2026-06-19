#include "apc.h"

int add(Dlist *list1_head, Dlist *list1_tail, Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Variable to store carry during addition
    int carry = 0;

    // Add digits while both lists have elements
    while(list1_tail != NULL && list2_tail != NULL)
    {
        // Add both digits along with carry
        int sum = list1_tail->data + list2_tail->data + carry;

        // Update carry
        carry = sum / 10;

        // Get current digit
        sum = sum % 10;

        // Extra carry check
        if(sum > 9)
        {
            carry = 1;
        }

        // Move to previous digit in first list
        list1_tail = list1_tail->prev;

        // Move to previous digit in second list
        list2_tail = list2_tail->prev;

        // Insert result digit at beginning of result list
        if(insert_first(res_head, res_tail, sum) == FAILURE)
        {
            return FAILURE;
        }
    }

    // Add remaining digits of first list
    while(list1_tail != NULL && list2_tail == NULL)
    {
        // Add digit and carry
        int sum = list1_tail->data + carry;

        // Update carry
        carry = sum / 10;

        // Get current digit
        sum = sum % 10;

        // Extra carry check
        if(sum > 9)
        {
            carry = 1;
        }

        // Move to previous digit
        list1_tail = list1_tail->prev;

        // Insert digit into result list
        if(insert_first(res_head, res_tail, sum) == FAILURE)
        {
            return FAILURE;
        }
    }

    // Add remaining digits of second list
    while(list1_tail == NULL && list2_tail != NULL)
    {
        // Add digit and carry
        int sum = list2_tail->data + carry;

        // Update carry
        carry = sum / 10;

        // Get current digit
        sum = sum % 10;

        // Extra carry check
        if(sum > 9)
        {
            carry = 1;
        }

        // Move to previous digit
        list2_tail = list2_tail->prev;

        // Insert digit into result list
        if(insert_first(res_head, res_tail, sum) == FAILURE)
        {
            return FAILURE;
        }
    }

    // Insert final carry if present
    if(carry != 0)
    {
        // Create new node for carry
        Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));
        // Check memory allocation
        if(newnode == NULL)
        {
            return FAILURE;
        }
        // Store carry in node
        newnode->data = carry;
        // Initialize links
        newnode->prev = NULL;
        newnode->next = NULL;
        // Insert node at beginning of result list
        newnode->next = *res_head;
        // Update previous pointer of old head
        (*res_head)->prev = newnode;
        // Update result head
        *res_head = newnode;
    }
    return SUCCESS;
}