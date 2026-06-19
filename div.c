#include "apc.h"

int divi(Dlist *list1_head,
         Dlist *list1_tail,
         Dlist *list2_head,
         Dlist *list2_tail,
         Dlist **res_head,
         Dlist **res_tail)
{
    // Check if any operand list is empty
    if(list1_head == NULL || list2_head == NULL)
        return FAILURE;

    /* Division by zero */

    // Check if divisor is zero
    if(list2_head->data == 0 && list2_head == list2_tail)
    {
        printf("Division by zero not allowed\n");
        return FAILURE;
    }

    // Temporary list to store current remainder
    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;

    // Initialize result list
    *res_head = NULL;
    *res_tail = NULL;

    // Pointer to traverse dividend
    Dlist *ptr = list1_head;

    // Traverse through dividend digits
    while(ptr != NULL)
    {
        /* STEP 1: Append digit to remainder */

        // Insert first digit into temp list
        if(temp_head == NULL)
        {
            insert_first(&temp_head, &temp_tail, ptr->data);
        }
        else
        {
            /* manual insert_last */

            // Create new node for next digit
            Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

            // Check memory allocation
            if(newnode == NULL)
                return FAILURE;

            // Store digit in node
            newnode->data = ptr->data;

            // Set node links
            newnode->next = NULL;
            newnode->prev = temp_tail;

            // Connect node at end of temp list
            temp_tail->next = newnode;

            // Update temp tail
            temp_tail = newnode;
        }

        /* Remove leading zeros in temp */

        // Remove unnecessary leading zeros in temp list
        while(temp_head != NULL &&
              temp_head->data == 0 &&
              temp_head != temp_tail)
        {
            // Store node to delete
            Dlist *del = temp_head;

            // Move head to next node
            temp_head = temp_head->next;

            // Update previous pointer
            temp_head->prev = NULL;

            // Free removed node
            free(del);
        }

        // Counter to store quotient digit
        int count = 0;

        /* STEP 2: Divide current remainder */

        // Repeated subtraction until temp becomes smaller than divisor
        while(compare_num(temp_head, list2_head) >= 0)
        {
            // Temporary result list after subtraction
            Dlist *new_head = NULL;
            Dlist *new_tail = NULL;

            // Subtract divisor from current remainder
            sub(temp_head,
                temp_tail,
                list2_head,
                list2_tail,
                &new_head,
                &new_tail);

            /* Free old temp */

            // Delete old remainder list
            while(temp_head != NULL)
            {
                Dlist *del = temp_head;

                // Move to next node
                temp_head = temp_head->next;

                // Free current node
                free(del);
            }

            // Update temp list with new subtraction result
            temp_head = new_head;
            temp_tail = new_tail;

            // Increment quotient count
            count++;
        }

        /* STEP 3: Store quotient digit */
        // Insert quotient digit into result list
        insert_first(res_head, res_tail, count);

        // Move to next dividend digit
        ptr = ptr->next;
    }

    /* Reverse result list */
    // Variables used for reversing linked list
    Dlist *prev = NULL;
    Dlist *curr = *res_head;
    Dlist *next = NULL;

    // Reverse quotient list
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    // Update result head and tail
    *res_tail = *res_head;
    *res_head = prev;

    /* Remove leading zeros */

    // Remove unnecessary leading zeros from quotient
    while(*res_head != NULL &&
          (*res_head)->data == 0 &&
          *res_head != *res_tail)
    {
        // Store node to delete
        Dlist *del = *res_head;
        // Move head to next node
        *res_head = (*res_head)->next;
        // Update previous pointer
        (*res_head)->prev = NULL;
        // Free removed node
        free(del);
    }
    return SUCCESS;
}