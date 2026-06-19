#include "apc.h"

int main(int argc, char *argv[])
{
    // Head and tail pointers for operand lists and result list.
    Dlist *list1_head = NULL, *list1_tail = NULL, *list2_head = NULL, *list2_tail = NULL, *res_head = NULL, *res_tail = NULL ;

    // printf("%d\n",argc);

    // Variables to store sign information of operands.
    int sign1 = 0, sign2 = 0;
    // Variable to store sign of final result.
    int result_sign = 0;
    // Validate number of command line arguments.
    if(argc != 4)
    {
        printf("Invalid number of arguments.\n");
        return 0;
    }
    // Store operand strings.
    char *num1 = argv[1];
    char *num2 = argv[3];
    // Check if first number is negative
    if(num1[0] == '-')
    {
        sign1 = 1;
        num1++; // Skip negative sign
    }
    // Check if second number is negative
    if(num2[0] == '-')
    {
        sign2 = 1;
        num2++; // Skip negative sign
    }
    // Proceed only if correct number of arguments are passed
    if(argc == 4)
    {
        // printf("Hello\n");
        // Validate whether operands contain only digits.
        if((validate_digits(argv[1]) && validate_digits(argv[3])) == FAILURE)
        {
            printf("Enter only digits.\n");
            return FAILURE;
        }
        else
        {
            printf("Digits validation done successfully.\n");
        }
        // Validate operator sign
        if(validate_sign(argv[2]) == SUCCESS)
        {
            printf("Sign validation is successfully done.\n");
        }
        else
        {
            printf("Enter proper sign for operation (+,-,*,/)\n");
            return FAILURE;
        }
        // Create linked list for first operand.
        if(create_list(num1, &list1_head, &list1_tail) == SUCCESS)
        {
            printf("List created successfully for 1st number.\n");
            // print_list(list1_head,list1_tail);
        }
        else
        {
            printf("List creation failed.\n");
            return FAILURE;
        }
        // Create linked list for second operand.
        if(create_list(num2, &list2_head, &list2_tail) == SUCCESS)
        {
            printf("List created successfully for 2nd number.\n");
            // print_list(list2_head,list2_tail);
        }
        else
        {
            printf("List creation failed.\n");
            return FAILURE;
        }
        // Store operator.
        char ch = argv[2][0];
        // Perform operation based on operator.
        switch(ch)
        {
            case '+':
                    // Initialize result sign.
                    result_sign = 0;
                    // If both numbers have same sign.
                    if(sign1 == sign2)
                    {
                        // Perform addition.
                        if(add(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail) == SUCCESS)
                        {
                            printf("Addition successfull.\n");
                            // Result sign will be same as operand sign
                            result_sign = sign1;
                            // print_list(res_head,res_tail);
                            // break;
                        }
                        else
                        {
                            printf("Addition failure.\n");
                            break;
                        }
                    }
                    else
                    {
                        // Compare numbers for subtraction
                        int compare = compare_num(list1_head, list2_head);
                        // If both numbers are equal
                        if(compare == 0)
                        {
                            insert_first(&res_head, &res_tail, 0);
                            result_sign = 0;
                        }
                        // If first number is greater
                        else if(compare > 0)
                        {
                            sub(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail);
                            result_sign = sign1;
                        }
                        // If second number is greater
                        else
                        {
                            sub(list2_head, list2_tail, list1_head, list1_tail, &res_head, &res_tail);
                            result_sign = sign2;
                        }
                    }
                    // printf("%d\n ",result_sign);
                    print_list(&result_sign, res_head, res_tail);
                    break;

            case '-':
                    // Initialize result sign
                    result_sign = 0;
                    // If signs are different
                    if(sign1 != sign2)
                    {
                        // Perform addition
                        add(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail);
                        // Result sign same as first operand
                        result_sign = sign1;
                    }
                    else
                    {
                        // Compare both operands
                        int compare = compare_num(list1_head, list2_head);
                        // printf("%d \n ",compare);
                        // If both numbers are equal
                        if(compare == 0)
                        {
                            insert_first(&res_head, &res_tail, 0);
                            result_sign = 0;
                            printf("Subtraction successfull.\n");
                        }
                        // If first number is greater
                        else if(compare > 0)
                        {
                            if(sub(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail) == SUCCESS)
                            {
                                printf("Subtraction successfull.\n");
                                result_sign = sign1;
                            }
                        }
                        // If second number is greater
                        else
                        {
                            if(sub(list2_head, list2_tail, list1_head, list1_tail, &res_head, &res_tail) == SUCCESS)
                            {
                                printf("Subtraction successfull.\n");
                                // Reverse sign of first operand
                                result_sign = !sign1;
                            }
                        }
                    }
                    print_list(&result_sign, res_head, res_tail);
                    break;

            case '*':
                    //Determine the sign of multiplication result.
                    result_sign = sign1 ^ sign2;
                    // Check if the first operand is zero.
                    if(list1_head->data == 0 && list1_head == list1_tail)
                    {
                        insert_first(&res_head, &res_tail, 0);
                        result_sign = 0;
                    }
                    // Check if the second operand is zero.
                    if(list2_head->data == 0 && list2_head == list2_tail)
                    {
                        insert_first(&res_head, &res_tail, 0);
                        result_sign = 0;
                    }
                    // Perform multiplication.
                    if(mul(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail) == SUCCESS)
                    {
                        printf("Multiplication successfull.\n");
                        print_list(&result_sign, res_head, res_tail);
                        break;
                    }
                    else
                    {
                        printf("Multiplication failure.\n");
                        break;
                    }

            case '/':
                    // Determine the sign of division result.
                    if(sign1 ^ sign2)
                    {
                        result_sign = 1;
                    }
                    else
                    {
                        result_sign = 0;
                    }
                    // Perform division.
                    if(divi(list1_head, list1_tail, list2_head, list2_tail, &res_head, &res_tail) == SUCCESS)
                    {
                        printf("Division successfull.\n");
                        print_list(&result_sign, res_head, res_tail);
                        break;
                    }
                    else
                    {
                        printf("Division failure.\n");
                        break;
                    }

            default:
                    {
                        printf("Enter a proper operator for operation.\n"); // Invalid operator case
                        break;
                    }
        }
    }
    else
    {
        printf("Invalid number of arguments.\n");   // Argument validation failure.
    }
}