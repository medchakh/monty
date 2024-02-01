#include "monty.h"

/**
 * open_file_func - Opens a file.
 * @file_n_name: The file name path.
 * Return: void
 */
void open_file_func(char *file_n_name)
{
	FILE *file_descriptor = fopen(file_n_name, "r");

	if (file_n_name == NULL || file_descriptor == NULL)
		err(2, file_n_name);

	read_file(file_descriptor);
	fclose(file_descriptor);
}

/**
 * read_file_func - Reads a file.
 * @fd: Pointer to file descriptor.
 * Return: void
 */
void read_file_func(FILE *fd)
{
	int line_num, format = 0;
	size_t leng = 0;
	char *buffer = NULL;

	for (line_num = 1; getline(&buffer, &leng, fd) != -1; line_num++)
	{
		format = parse_line(buffer, line_num, format);
	}
	free(buffer);
}

/**
 * parse_line_func - Separates each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @line_num: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *            If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line_func(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func_func(opcode, value, line_num, format);
	return (format);
}

/**
 * find_func - Finds the appropriate function for the opcode.
 * @op_code: Opcode.
 * @val: Argument of opcode.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 *            If 1, nodes will be entered as a queue.
 * @ln: Line number.
 */
void find_func_func(char *op_code, char *val, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"pall", print_stack},
		{"push", add_to_stack_func},
		{"nop", nop},
		{"pop", pop_top},
		{"pint", print_top},
		{"swap", swap_nodes},
		{"add", add_nodes_func},
		{"sub", sub_nodes_func},
		{"div", div_nodes_func},
		{"mul", mul_nodes_func},
		{"pchar", print_char_func},
		{"mod", mod_nodes_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{"pstr", print_str_func},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, op_code, val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, op_code);
}

/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: String representing the opcode.
 * @val: String representing a numeric value.
 * @ln: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
