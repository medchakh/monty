#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a new node.
 * @n: Number to be stored in the node.
 * Return: Upon success, returns a pointer to the new node. Otherwise, returns NULL.
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
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
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
 * add_to_queue_func - Adds a new node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void add_to_queue_func(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
