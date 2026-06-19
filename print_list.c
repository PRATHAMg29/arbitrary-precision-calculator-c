#include "apc.h"

int print_list(int *sign,Dlist *head, Dlist *tail)
{
    if (head == NULL)
	{
		printf("INFO : List is empty\n");
        return FAILURE;
	}
	else
	{
	    printf("Result -> ");
		if(*sign == 1)
			printf("-");
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> next;
		    // if (head)
		    //     printf("> ");
	    }
    	printf("\n");
    }
    return SUCCESS;
}