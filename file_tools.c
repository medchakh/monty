#include "monty.h"

/**
 * open_file_func - open a file
 * @file_dec: the file name-path
 * Return: void
 */

void open_file_func(char *file_dec)
{
	FILE *fd = fopen(file_dec, "r");

	if (file_dec == NULL || fd == NULL)
		err(2, file_dec);

	read_file_func(fd);
	fclose(fd);
}


/**
 * read_file_func - read a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file_func(FILE *fd)
{
	int line_num, frmt = 0;
	char *buffer = NULL;
	size_t leng = 0;

	for (line_num = 1; getline(&buffer, &leng, fd) != -1; line_num++)
	{
		frmt = parse_line_func(buffer, line_num, frmt);
	}
	free(buffer);
}


/**
 * parse_line_func - Separates each line into tokens 
 * which function to call
 * @buffer: line from the file
 * @line_num: line number
 * @frmt:  storage frmt. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line_func(char *buffer, int line_num, int frmt)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (frmt);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func_func(opcode, value, line_num, frmt);
	return (frmt);
}

/**
 * find_func_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @frmt:  storage frmt. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func_func(char *opcode, char *value, int ln, int frmt)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack_func},
		{"pall", print_stack_func},
		{"pint", print_top_func},
		{"pop", pop_top_func},
		{"nop_func", nop_func},
		{"swap", swap_nodes_func},
		{"add", add_nodes_func},
		{"sub", add_nodes_func},
		{"div", div_nodes_func},
		{"mul", mull_nodes_func},
		{"mod", mod_nodes_func},
		{"pchar", print_char_func},
		{"pstr", print_string_func},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun_func(func_list[i].f, opcode, value, ln, frmt);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @frmt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun_func(op_func func, char *op, char *val, int ln, int frmt)
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
		if (frmt == 0)
			func(&node, ln);
		if (frmt == 1)
			add_to_queue_func(&node, ln);
	}
	else
		func(&head, ln);
}
