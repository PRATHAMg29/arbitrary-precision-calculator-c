#include "apc.h"

int insert_first(Dlist **res_head, Dlist **res_tail, int data)
{
    // Create new node
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));

    // Check memory allocation
    if(newnode == NULL)
    {
        return FAILURE;
    }

    // Store data in node
    newnode->data = data;

    // Initialize node pointers
    newnode->prev = NULL;
    newnode->next = NULL;

    // Check if list is empty
    if(*res_head == NULL)
    {
        // Make new node as head and tail
        *res_head = newnode;
        *res_tail = newnode;
    }
    else
    {
        // Connect new node at beginning of list
        newnode->next = *res_head;
        // Update previous pointer of old head
        (*res_head)->prev = newnode;
        // Update head pointer
        *res_head = newnode;
    }
    return SUCCESS;
}