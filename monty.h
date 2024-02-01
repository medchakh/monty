#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file ops*/
int parse_line_func(char *buffer, int line_number, int format);
void open_file_func(char *file_name);
int len_chars_func(FILE *);
void find_func_func(char *, char *, int, int);
void read_file_func(FILE *);

/*Stack ops*/
stack_t *create_node(int n);
void print_stack_func(stack_t **, unsigned int);
void add_to_stack_func(stack_t **, unsigned int);
void add_to_queue_func(stack_t **, unsigned int);
void free_nodes_func(void);

void print_top_func(stack_t **, unsigned int);

void call_fun_func(op_func, char *, char *, int, int);
void swap_nodes_func(stack_t **, unsigned int);
void nop_func(stack_t **, unsigned int);
void pop_top_func(stack_t **, unsigned int);

/*Math ops for nodes*/
void sub_nodes_func(stack_t **, unsigned int);
void add_nodes_func(stack_t **, unsigned int);
void mod_nodes_func(stack_t **, unsigned int);
void mull_nodes_func(stack_t **, unsigned int);
void div_nodes_func(stack_t **, unsigned int);

/*String ops*/
void print_string_func(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void print_char_func(stack_t **, unsigned int);

/*Error hanlding ops*/
void more_err_func(int error_code, ...);
void err(int error_code, ...);
void rotr(stack_t **, unsigned int);
void string_error_func(int error_code, ...);

#endif
