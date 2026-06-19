#include "apc.h"

int create_list(char argv[], Dlist **head, Dlist **tail)
{
    // Initialize index variable
    int i = 0;

    // Skip leading zeros
    while(argv[i] == '0')
    {
        i++;
    }

    // If entire number is zero
    if(argv[i] == '\0')
    {
        // Insert single zero node
        insert_first(head, tail, 0);

        // Return success
        return SUCCESS;
    }

    // Traverse input string
    while(argv[i])
    {
        // Create new node
        Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

        // Check memory allocation
        if(newnode == NULL)
        {
            return FAILURE;
        }

        // Initialize node pointers
        newnode->prev = NULL;
        newnode->next = NULL;

        // Convert character digit to integer
        int num = argv[i] - '0';

        // Store digit in node
        newnode->data = num;

        // If list is empty
        if(*head == NULL)
        {
            // Initialize head and tail
            *head = newnode;
            *tail = newnode;
        }
        else
        {
            // Connect node at end of list
            newnode->prev = *tail;
            (*tail)->next = newnode;
            // Update tail pointer
            *tail = newnode;
        }
        // Move to next character
        i++;
    }
    return SUCCESS;
}