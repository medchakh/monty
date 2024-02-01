#include "monty.h"

/**
 * mul_nodes_func - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void mul_nodes_func(stack_t **stack, unsigned int line_num)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes_func - Computes the remainder of the division of the second top
 * element by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void mod_nodes_func(stack_t **stack, unsigned int line_num)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_num);

	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
