#include "monty.h"

/**
 * nop_func - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void nop_func(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swap_nodes_func - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void swap_nodes_func(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_func(8, line_num, "swap");
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
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void add_nodes_func(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_func(8, line_num, "add");

	(*stack) = (*stack)->next;
	summ = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes_func - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub_nodes_func(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err_func(8, line_num, "sub");


	(*stack) = (*stack)->next;
	summ = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes_func - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_nodes_func(stack_t **stack, unsigned int line_num)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err_func(8, line_num, "div");

	if ((*stack)->n == 0)
		more_err_func(9, line_num);
	(*stack) = (*stack)->next;
	summ = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
