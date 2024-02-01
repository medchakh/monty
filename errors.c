#include "monty.h"

/**
 * err - Prints appropriate error messages based on the given error code.
 * @error_code: The error codes and their meanings:
 * (1) => No file or more than one file provided to the program.
 * (2) => The specified file cannot be opened or read.
 * (3) => The file contains an invalid instruction.
 * (4) => Unable to allocate more memory (malloc failed).
 * (5) => The parameter passed to the "push" instruction is not an integer.
 * (6) => Stack is empty for "pint" operation.
 * (7) => Stack is empty for "pop" operation.
 * (8) => Stack is too short for the operation.
 */

void err_func(int error_err_code, ...)
{
	va_list ag;
	char *op_p;
	int l_num_int;

	va_start(ag, error_err_code);
	switch (error_err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num_int = va_arg(ag, int);
			op_p = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num_int, op_p);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Manages error cases.
 * @error_err_code: The error codes and their meanings:
 *   (6) => Stack is empty for "pint" operation.
 *   (7) => Stack is empty for "pop" operation.
 *   (8) => Stack is too short for the operation.
 *   (9) => Division by zero.
 */
void more_err_func(int error_err_code, ...)
{
	va_list ag;
	char *op_p;
	int l_num_int;

	va_start(ag, error_err_code);
	switch (error_err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num_int = va_arg(ag, unsigned int);
			op_p = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num_int, op_p);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Manages error cases.
 * @error_err_code: The error codes and their meanings:
 *   (10) => The number inside a node is outside ASCII bounds.
 *   (11) => The stack is empty.
 */
void string_err_func(int error_err_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_err_code);
	l_num = va_arg(ag, int);
	switch (error_err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
