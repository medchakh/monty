#include "monty.h"

/**
 * nop - Performs no operation.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * swap_nodes - Swaps the positions of the top two elements in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes_func - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void add_nodes_func(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes_func - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void sub_nodes_func(stack_t **stack, unsigned int line_num)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "sub");

	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes_func - Divides the second top element by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void div_nodes_func(stack_t **stack, unsigned int line_num)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "div");

	if ((*stack)->n == 0)
		more_err(9, line_num);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
