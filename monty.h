#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data - All data in the program
 * @push_value: Value to push
 * @line_num: Line number of opcode
 * @opcode: The opcode
 * @mfile: File to open
 * @top: The top of the stack
 * @mode: 0 means stack, 1 means queue
 * In stack, you push in the start
 * In the queue, you push at the end
 */
typedef struct data
{
    int push_value;
    unsigned int line_num;
    char *opcode;
    FILE *mfile;
    stack_t *top;
    int mode;
} data;
data datax;

void exec(void);
int main(int argc, char **argv);

void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void _pint(stack_t **top, unsigned int line_number);
void _pop(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);
void _pchar(stack_t **top, unsigned int line_number);
void _pstr(stack_t **top, unsigned int line_number);
void _rotl(stack_t **top, unsigned int line_number);
void _rotr(stack_t **top, unsigned int line_number);
void _mode(stack_t **top, unsigned int line_number);

FILE *openfile(char *filename);
size_t num_len(int num);
void verify_number(char *token);
void free_stack(stack_t *top);

#endif
