#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdarg.h>

//MACROS
#define SUCCESS 1
#define FAILURE 0

typedef struct doublelist
{
    int data;
    struct doublelist *prev;
    struct doublelist *next;
}Dlist;

//function prototypes.
int insert_first(Dlist **res_head, Dlist **res_tail, int data);
int validate_digits(char argv[]);
int validate_sign(char argv[]);
int create_list(char argv[],Dlist **head,Dlist **tail);
int print_list(int *sign,Dlist *head, Dlist *tail);
int add(Dlist *list1_head, Dlist *list1_tail,Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail);
int sub(Dlist *list1_head, Dlist *list1_tail,Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail);
int compare_num(Dlist *head1, Dlist *head2);
int mul(Dlist *list1_head, Dlist *list1_tail,Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail);
int divi(Dlist *list1_head, Dlist *list1_tail,Dlist *list2_head, Dlist *list2_tail, Dlist **res_head, Dlist **res_tail);


#endif