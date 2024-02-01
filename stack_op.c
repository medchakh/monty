#include "monty.h"

/**
 * mull_nodes_func - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mull_nodes_func(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_func(8, line_num, "mul");

	(*stack) = (*stack)->next;
	summ = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes_func - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mod_nodes_func(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err_func(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_err_func(9, line_num);
	(*stack) = (*stack)->next;
	summ = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
