#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file_func(argv[1]);
	free_nodes_func();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes_func - Frees nodes in the stack.
 */
void free_nodes_func(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_queue_func - Adds a node to the queue.
 * @new_nd: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue_func(stack_t **new_nd, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_nd == NULL || *new_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_nd;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_nd;
	(*new_nd)->prev = tmp;

}
