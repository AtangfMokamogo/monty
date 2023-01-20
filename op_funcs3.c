#include "monty.h"

/**
 * my_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}

/**
 * my_pchar - Prints the character in the top value node of a
 *           stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_pchar(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		set_error(err_pchar(line_no, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_error(err_pchar(line_no, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}


/**
 * my_pstring - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_pstring(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_no;
}



/**
 * set_error - Sets last element of op_toks to be an error code.
 * @error: Integer to store as a string in op_toks.
 */
void set_error(int error)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_token = NULL;

	token_len = token_arr_len();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!op_toks)
	{
		err_malloc();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error);
	if (!exit_str)
	{
		free(new_token);
		err_malloc();
		return;
	}
	new_token[i++] = exit_str;
	new_token[i] = NULL;
	free(op_toks);
	op_toks = new_token;
}
