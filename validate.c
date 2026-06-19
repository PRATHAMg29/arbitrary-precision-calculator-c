#include "apc.h"

int validate_digits(char argv[])    //VALIDATION FOR DIGITS
{
    int i=0;
    if(argv[0] == '-')
        i++;
    while(argv[i])
    {
        if(!isdigit(argv[i]))
        {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}

int validate_sign(char argv[])  //VALIDATION FOR SIGN
{
    int i=0,count=0;
    while(argv[i])
    {
        if(argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
        {
            count++;
        }
        i++;
    }
    if(count == 1)
        return SUCCESS;
    else
        return FAILURE;
}

int compare_num(Dlist *head1, Dlist *head2) 
{
    int count1 = 0,count2 = 0;
    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    while(temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    int len1 = count1;
    while(temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    int len2 = count2;
    if(len1 > len2)
        return 1;
    if(len1 < len2)
        return -1;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
            return 1;
        if(head1->data < head2->data)
            return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}