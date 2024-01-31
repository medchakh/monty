#include "monty.h"

/**
 * open_file - Open a file and return a FILE pointer.
 * @filename: Name of the file to open.
 * Return: FILE pointer.
 */
FILE *open_file(char *filename)
{
    FILE *mfile;

    mfile = fopen(filename, "r");
    if (!mfile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return mfile;
}

/**
 * num_len - Count the number of digits in an integer.
 * @num: The number to determine the length of.
 * Return: The number of digits in the integer.
 */
size_t num_len(int num)
{
    int len = 0;

    if (!num)
        return 1;
    if (num <= 0)
        len++;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

/**
 * verify_number - Verify if the number for the push opcode is valid.
 * @token: Token string representing a number.
 * Return: None.
 */
void verify_number(char *token)
{
    int i = 0;

    if (atoi(token) < 0)
        i++;
    if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
        (token[0] == '-' && isdigit(token[1])))
        datax.push_value = atoi(token);
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
        free_stack(datax.top);
        exit(EXIT_FAILURE);
    }
}

/**
 * free_stack - Frees the memory occupied by a stack.
 * @top: Head of the stack.
 * Return: None.
 */
void free_stack(stack_t *top)
{
    stack_t *nav, *nav2;

    nav = top;
    while (nav)
    {
        nav2 = nav->next;
        free(nav);
        nav = nav2;
    }
    datax.top = NULL;
    fclose(datax.mfile);
}
