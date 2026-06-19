# Arbitrary Precision Calculator using C

## Overview

Developed an Arbitrary Precision Calculator (APC) in C to perform arithmetic operations on very large numbers beyond the storage limits of built-in data types. The project uses Linked Lists to represent and process large numerical values digit by digit, enabling operations on numbers of virtually any length.

## Features

- Addition of large numbers
- Subtraction of large numbers
- Multiplication of large numbers
- Division of large numbers
- Supports numbers larger than standard C data type limits
- Linked List based number representation
- Command Line Argument support
- Input validation for arithmetic operations

## Technologies & Concepts Used

- C Programming
- Linked Lists
- Dynamic Memory Allocation
- Functions
- Structures
- Command Line Arguments
- Data Structures

## Project Structure

.
├── add.c
├── sub.c
├── mul.c
├── div.c
├── create_list.c
├── insert_first.c
├── print_list.c
├── validate.c
└── apc.h

## Data Structure Used

Linked List

Example:

123456789123456789

↓

1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → ...

Each digit is stored in a separate node, allowing arithmetic operations on numbers that exceed the limits of built-in data types.

## How to Run

### Compile

gcc *.c -o apc

### Execute

./apc <operand1> <operator> <operand2>

### Examples

./apc 123456789123456789 + 987654321987654321

./apc 999999999999999999 * 888888888888888888

## Supported Operations

+
-
*
/
